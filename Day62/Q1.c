#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct AdjList {
    Node* head;
} AdjList;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(AdjList* list, int u, int v) {
    // Add v to u's list
    Node* newNode = createNode(v);
    newNode->next = list[u].head;
    list[u].head = newNode;
    newNode = createNode(u);
    newNode->next = list[v].head;
    list[v].head = newNode;
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    AdjList* list = (AdjList*)malloc(n * sizeof(AdjList));
    for (int i = 0; i < n; i++) list[i].head = NULL;

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(list, u, v);
    }
    for (int i = 0; i < n; i++) {
        Node* curr = list[i].head;
        printf("Vertex %d:", i);
        while (curr) {
            printf(" -> %d", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }

    return 0;
}