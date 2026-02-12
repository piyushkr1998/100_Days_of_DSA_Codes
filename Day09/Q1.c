#include <stdio.h>

int main()
{
    char str[100];
    int i, len = 0;
    char temp;

    scanf("%s", str);

    while(str[len] != '\0')
        len++;

    for(i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("%s", str);

    return 0;
}
