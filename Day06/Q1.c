#include <stdio.h>

int main()
{
    int a[100], n, i, j = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++)
    {
        if(a[i] != a[j])
        {
            j++;
            a[j] = a[i];
        }
    }

    for(i = 0; i <= j; i++)
        printf("%d ", a[i]);

    return 0;
}
