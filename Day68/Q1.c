#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
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

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    while (!isEmpty()) {

        int current = dequeue();
        printf("%d ", current);
        count++;
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }
    if (count != n) {
        printf("\nCycle detected (Topological sort not possible)");
    }

    return 0;
}