#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strsort(char* *s, int n)
{
    char *temp;
    char **p1, **p2;
    for (p1 = s; p1 < s + n - 1; p1++)
    {
        for (p2 = s; p2 < s + n - (p1 - s) - 1; p2++)
        {
            if (strcmp(*p2, *(p2 + 1)) > 0)
            {
                temp = *p2;
                *p2 = *(p2 + 1);
                *(p2 + 1) = temp;
            }
        }
    }
}

int main()
{
    int i, N;
    scanf("%d", &N);
    getchar();
    char *s[N],t[50];
    for (i = 0; i < N; i++)
    {
        gets(t);
        *(s+i) = (char *)malloc(strlen(t) + 1);
        strcpy(*(s+i), t);
    }
    strsort(s, N);
    for (i = 0; i < N; i++)
        puts(*(s+i));
    return 0;
}
