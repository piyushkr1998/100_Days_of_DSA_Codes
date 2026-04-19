#include <stdio.h>
#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int visited[MAX];
int n;

int minKey(int key[]) {
    int min = INF, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {

    int m, u, v, w;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int key[MAX];     
    int parent[MAX];  

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        key[i] = INF;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    key[1] = 0;
    parent[1] = -1;

    int totalCost = 0;

    for (int count = 1; count <= n; count++) {

        int u = minKey(key);
        visited[u] = 1;

        totalCost += key[u];
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("%d", totalCost);

    return 0;
}