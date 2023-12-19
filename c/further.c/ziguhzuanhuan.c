#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[81];
    int k;
    gets(s);
    scanf("%d", &k);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
        }
    }
    int a = strlen(s);
    /*for (int i = 0, j = a - 1; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        }   */
    puts(s);
    return 0;
}
