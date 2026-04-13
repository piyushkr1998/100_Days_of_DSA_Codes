#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;   // -1 means empty
    }
}
int hash(int key, int m) {
    return key % m;
}
void insert(int key, int m) {
    int index = hash(key, m);

    int i = 0;
    while (table[(index + i*i) % m] != -1 && i < m) {
        i++;
    }

    if (i < m) {
        table[(index + i*i) % m] = key;
    }
}
void search(int key, int m) {
    int index = hash(key, m);

    int i = 0;
    while (table[(index + i*i) % m] != -1 && i < m) {

        if (table[(index + i*i) % m] == key) {
            printf("FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {

    int m, n;
    scanf("%d", &m);  
    scanf("%d", &n);   

    init();

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}