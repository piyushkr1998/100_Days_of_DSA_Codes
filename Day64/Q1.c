#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n;
void enqueue(int x) {
    queue[rear++] = x;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
void bfs(int s) {
    visited[s] = 1;
    enqueue(s);

    while (!isEmpty()) {

        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {

    int s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    bfs(s);

    return 0;
}