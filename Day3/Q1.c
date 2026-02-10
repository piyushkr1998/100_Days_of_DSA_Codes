#include <stdio.h>

int main()
{
    int a[100], n, k, i, found = 0, comp = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        comp++;
        if(a[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Not Found\n");

    printf("Comparisons = %d", comp);

    return 0;
}
