#include <stdio.h>
#include <limits.h>

#define I INT_MAX

int minDistance(int dist[], int sptSet[], int vertices) {
    int min = I, min_index;

    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int graph[5][5], int src, int vertices) {
    int dist[vertices];
    int sptSet[vertices];
    int parent[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = I;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != I && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t %d\t\t", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int graph[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int sourceVertex = 0;
    dijkstra(graph, sourceVertex, 5);

    return 0;
}
