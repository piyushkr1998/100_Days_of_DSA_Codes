#include <stdio.h>

#define MAX 1000

int main() {

    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    int hash[2001];  
    for (int i = 0; i < 2001; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int index = sum + 1000;

        if (hash[index] != -1) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        }
        else {
          
            hash[index] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}