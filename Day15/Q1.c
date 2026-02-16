#include <stdio.h>

int main() {
    int m, n;
    int a[50][50];
    int sum = 0;
    
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("%d\n", sum);

    return 0;
}
