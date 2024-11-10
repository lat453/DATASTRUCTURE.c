#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LOCATIONS 100

typedef struct {
    int distance[MAX_LOCATIONS][MAX_LOCATIONS];
    int numLocations;
} Graph;

void initGraph(Graph *graph, int numLocations) {
    graph->numLocations = numLocations;
    for (int i = 0; i < numLocations; i++) {
        for (int j = 0; j < numLocations; j++) {
            if (i == j) graph->distance[i][j] = 0;
            else graph->distance[i][j] = INT_MAX;
        }
    }
}

void addRoute(Graph *graph, int start, int end, int distance) {
    graph->distance[start][end] = distance;
    graph->distance[end][start] = distance;
}

void removeRoute(Graph *graph, int start, int end) {
    graph->distance[start][end] = INT_MAX;
    graph->distance[end][start] = INT_MAX;
}

int minDistance(int dist[], int sptSet[], int numLocations) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numLocations; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v], minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(Graph *graph, int start, int end) {
    int dist[MAX_LOCATIONS], sptSet[MAX_LOCATIONS];
    for (int i = 0; i < graph->numLocations; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < graph->numLocations - 1; count++) {
        int u = minDistance(dist, sptSet, graph->numLocations);
        sptSet[u] = 1;

        for (int v = 0; v < graph->numLocations; v++) {
            if (!sptSet[v] && graph->distance[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph->distance[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->distance[u][v];
            }
        }
    }

    if (dist[end] == INT_MAX) {
        printf("No path exists from %d to %d.\n", start, end);
    } else {
        printf("Shortest path from %d to %d is %d.\n", start, end, dist[end]);
    }
}

int main() {
    Graph graph;
    int numLocations, numRoutes;

    printf("Enter the number of locations: ");
    scanf("%d", &numLocations);
    initGraph(&graph, numLocations);

    printf("Enter the number of routes: ");
    scanf("%d", &numRoutes);
    
    for (int i = 0; i < numRoutes; i++) {
        int start, end, distance;
        printf("Enter start, end, and distance for route %d: ", i + 1);
        scanf("%d %d %d", &start, &end, &distance);
        addRoute(&graph, start, end, distance);
    }

    int start, end;
    printf("Enter start and end locations for shortest path calculation: ");
    scanf("%d %d", &start, &end);
    dijkstra(&graph, start, end);

    return 0;
}
