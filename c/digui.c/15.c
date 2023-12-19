#include <stdio.h>
#include <string.h> //判断回文

int is_palindrome(char s[], int start, int end)
{
    if (start >= end)
    {
        return 1;
    }
    if (s[start] == s[end])
    {
        return is_palindrome(s, start + 1, end - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    int len = strlen(s);
    if (is_palindrome(s, 0, len - 1))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
