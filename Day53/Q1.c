#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000

struct Node {
    int data;
    struct Node *left, *right;
};
struct QueueNode {
    struct Node* treeNode;
    int hd;
};

struct ListNode {
    int val;
    struct ListNode* next;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void printVerticalOrder(struct Node* root, int n) {
    if (!root) return;
    struct ListNode* map[2 * n + 1];
    struct ListNode* tail[2 * n + 1];
    for (int i = 0; i < 2 * n + 1; i++) {
        map[i] = NULL;
        tail[i] = NULL;
    }

    struct QueueNode queue[MAX_NODES];
    int head = 0, q_tail = 0;
    int min_hd = 0, max_hd = 0;

    queue[q_tail++] = (struct QueueNode){root, 0};

    while (head < q_tail) {
        struct QueueNode curr = queue[head++];
        struct Node* tNode = curr.treeNode;
        int hd = curr.hd;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        struct ListNode* newLNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newLNode->val = tNode->data;
        newLNode->next = NULL;

        int index = hd + n; 
        if (map[index] == NULL) {
            map[index] = newLNode;
            tail[index] = newLNode;
        } else {
            tail[index]->next = newLNode;
            tail[index] = newLNode;
        }

        if (tNode->left) queue[q_tail++] = (struct QueueNode){tNode->left, hd - 1};
        if (tNode->right) queue[q_tail++] = (struct QueueNode){tNode->right, hd + 1};
    }

    for (int i = min_hd + n; i <= max_hd + n; i++) {
        struct ListNode* temp = map[i];
        while (temp) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}
struct Node* buildTree(int n, int arr[]) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[n];
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n && f < r) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(n, arr);
    printVerticalOrder(root, n);

    return 0;
}