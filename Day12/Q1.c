#include <stdio.h>

int main() {
    int m, n;
    int a[50][50];
    int flag = 1;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if(m != n) {
        printf("Not Symmetric\n");
        return 0;
    }

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        printf("Symmetric\n");
    else
        printf("Not Symmetric\n");

    return 0;
}
