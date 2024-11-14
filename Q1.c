#include <limits.h>
#include <stdio.h>

#define I INT_MAX

int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I}
};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6];

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};
int included[9] = {0};

void Myunion(int u, int v) {
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) {
    if (set[u] < 0) return u;
    return set[u] = find(set[u]);
}

void prim() {
    int i, j, k, u, v, min = I, n = 7;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (i = 1; i <= n; i++) {
        if (near[i] != 0) {
            near[i] = (cost[i][u] < cost[i][v]) ? u : v;
        }
    }
    for (i = 1; i < n - 1; i++) {
        min = I;
        for (j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }
    printf("Edges of MST using Prim's algorithm:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d) with cost %d\n", t[0][i], t[1][i], cost[t[0][i]][t[1][i]]);
    }
}

void kruskal() {
    int i = 0, j, k, u, v, min, n = 7, e = 9;
    while (i < n - 1) {
        min = I;
        for (j = 0; j < e; j++) {
            if (included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j] - 1;
                v = edges[1][j] - 1;
                k = j;
            }
        }
        if (find(u) != find(v)) {
            t[0][i] = u + 1;
            t[1][i] = v + 1;
            Myunion(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }
    printf("Edges of MST using Kruskal's algorithm:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d) with cost %d\n", t[0][i], t[1][i], edges[2][i]);
    }
}

int main() {
    int choice;
    printf("Choose the algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            prim();
            break;
        case 2:
            kruskal();
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
