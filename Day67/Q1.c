#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

/* DFS function */
void dfs(int v) {

    visited[v] = 1;

    // Visit all neighbors
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    // Push to stack after visiting children
    stack[++top] = v;
}

int main() {

    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order (reverse of stack)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}