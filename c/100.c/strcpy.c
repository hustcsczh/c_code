#include <stdio.h>
#define SIZE 100
void strnCpy(char *s, char *t, int n);
int main()
{
    /**********  Begin  **********/
    int n;
    char arr[SIZE];
    char out[SIZE];
    scanf("%[^\n]", &arr);
    scanf("%d", &n);
    strnCpy(out, arr, n);
    printf("%s", out);
    /**********  Begin  **********/
    return 0;
}
void strnCpy(char *s, char *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        *s++ = *t++;
    }
    *s = '\0';
}