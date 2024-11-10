#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LOCATIONS 100

typedef struct {
    int cost[MAX_LOCATIONS][MAX_LOCATIONS];
    int numLocations;
} Graph;

void initGraph(Graph *graph, int numLocations) {
    graph->numLocations = numLocations;
    for (int i = 0; i < numLocations; i++) {
        for (int j = 0; j < numLocations; j++) {
            if (i == j) graph->cost[i][j] = 0;
            else graph->cost[i][j] = INT_MAX;
        }
    }
}

void addRoad(Graph *graph, int start, int end, int cost) {
    graph->cost[start][end] = cost;
    graph->cost[end][start] = cost;
}

int minKey(int key[], int mstSet[], int numLocations) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numLocations; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], minIndex = v;
        }
    }
    return minIndex;
}

void primMST(Graph *graph) {
    int parent[MAX_LOCATIONS], key[MAX_LOCATIONS], mstSet[MAX_LOCATIONS];
    for (int i = 0; i < graph->numLocations; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->numLocations - 1; count++) {
        int u = minKey(key, mstSet, graph->numLocations);
        mstSet[u] = 1;

        for (int v = 0; v < graph->numLocations; v++) {
            if (graph->cost[u][v] != INT_MAX && mstSet[v] == 0 && graph->cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->cost[u][v];
            }
        }
    }

    printf("Minimum road construction costs (MST):\n");
    for (int i = 1; i < graph->numLocations; i++) {
        printf("Location %d - Location %d: %d\n", parent[i], i, graph->cost[i][parent[i]]);
    }
}

int main() {
    Graph graph;
    int numLocations, numRoads;

    printf("Enter the number of locations: ");
    scanf("%d", &numLocations);
    initGraph(&graph, numLocations);

    printf("Enter the number of roads: ");
    scanf("%d", &numRoads);
    
    for (int i = 0; i < numRoads; i++) {
        int start, end, cost;
        printf("Enter start, end, and cost for road %d: ", i + 1);
        scanf("%d %d %d", &start, &end, &cost);
        addRoad(&graph, start, end, cost);
    }

    primMST(&graph);

    return 0;
}
