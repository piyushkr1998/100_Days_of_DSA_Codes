#include <stdio.h>

int main()
{
    char s[100];
    int left = 0, right = 0;

    scanf("%s", s);

    while(s[right] != '\0')
        right++;

    right--;  

    while(left < right)
    {
        if(s[left] != s[right])
        {
            printf("Not Palindrome");
            return 0;
        }
        left++;
        right--;
    }

    printf("Palindrome");
    return 0;
}
