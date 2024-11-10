#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TOWNS 100

typedef struct {
    int cost[MAX_TOWNS][MAX_TOWNS];
    int numTowns;
} Graph;

void initGraph(Graph *graph, int numTowns) {
    graph->numTowns = numTowns;
    for (int i = 0; i < numTowns; i++) {
        for (int j = 0; j < numTowns; j++) {
            if (i == j) graph->cost[i][j] = 0;
            else graph->cost[i][j] = INT_MAX;
        }
    }
}

void addPowerLine(Graph *graph, int start, int end, int cost) {
    graph->cost[start][end] = cost;
    graph->cost[end][start] = cost;
}

int minKey(int key[], int mstSet[], int numTowns) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numTowns; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], minIndex = v;
        }
    }
    return minIndex;
}

void primMST(Graph *graph) {
    int parent[MAX_TOWNS], key[MAX_TOWNS], mstSet[MAX_TOWNS];
    for (int i = 0; i < graph->numTowns; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->numTowns - 1; count++) {
        int u = minKey(key, mstSet, graph->numTowns);
        mstSet[u] = 1;

        for (int v = 0; v < graph->numTowns; v++) {
            if (graph->cost[u][v] != INT_MAX && mstSet[v] == 0 && graph->cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->cost[u][v];
            }
        }
    }

    printf("Minimum power line cost to connect towns (MST):\n");
    for (int i = 1; i < graph->numTowns; i++) {
        printf("Town %d - Town %d: %d\n", parent[i], i, graph->cost[i][parent[i]]);
    }
}

int main() {
    Graph graph;
    int numTowns, numPowerLines;

    printf("Enter the number of towns: ");
    scanf("%d", &numTowns);
    initGraph(&graph, numTowns);

    printf("Enter the number of power lines: ");
    scanf("%d", &numPowerLines);
    
    for (int i = 0; i < numPowerLines; i++) {
        int start, end, cost;
        printf("Enter start, end, and cost for power line %d: ", i + 1);
        scanf("%d %d %d", &start, &end, &cost);
        addPowerLine(&graph, start, end, cost);
    }

    primMST(&graph);

    return 0;
}
