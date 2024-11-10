#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_OFFICES 100

typedef struct {
    int cost[MAX_OFFICES][MAX_OFFICES];
    int numOffices;
} Graph;

void initGraph(Graph *graph, int numOffices) {
    graph->numOffices = numOffices;
    for (int i = 0; i < numOffices; i++) {
        for (int j = 0; j < numOffices; j++) {
            if (i == j) graph->cost[i][j] = 0;
            else graph->cost[i][j] = INT_MAX;
        }
    }
}

void addCable(Graph *graph, int start, int end, int cost) {
    graph->cost[start][end] = cost;
    graph->cost[end][start] = cost;
}

int minKey(int key[], int mstSet[], int numOffices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numOffices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], minIndex = v;
        }
    }
    return minIndex;
}

void primMST(Graph *graph) {
    int parent[MAX_OFFICES], key[MAX_OFFICES], mstSet[MAX_OFFICES];
    for (int i = 0; i < graph->numOffices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->numOffices - 1; count++) {
        int u = minKey(key, mstSet, graph->numOffices);
        mstSet[u] = 1;

        for (int v = 0; v < graph->numOffices; v++) {
            if (graph->cost[u][v] != INT_MAX && mstSet[v] == 0 && graph->cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->cost[u][v];
            }
        }
    }

    printf("Minimum cable length for connecting offices (MST):\n");
    for (int i = 1; i < graph->numOffices; i++) {
        printf("Office %d - Office %d: %d\n", parent[i], i, graph->cost[i][parent[i]]);
    }
}

int main() {
    Graph graph;
    int numOffices, numCables;

    printf("Enter the number of offices: ");
    scanf("%d", &numOffices);
    initGraph(&graph, numOffices);

    printf("Enter the number of cables: ");
    scanf("%d", &numCables);
    
    for (int i = 0; i < numCables; i++) {
        int start, end, cost;
        printf("Enter start, end, and cost for cable %d: ", i + 1);
        scanf("%d %d %d", &start, &end, &cost);
        addCable(&graph, start, end, cost);
    }

    primMST(&graph);

    return 0;
}
