#include <stdio.h>
#include <string.h>
#define MAXLEN 63
int keyword(char *s);
int main()
{
    char s[MAXLEN + 1];
    printf("input string:");
    while (scanf("%s", s) != EOF)
        if (keyword(s))
            printf("%s is key word", s);
        else
            printf("no key word");
    return 0;
}
int keyword(char *s) // 字符串数组做函数参数 char *s
{
    static char *keyword[] = {"char", "auto", "continue", "if"}; // 字符串数组
    int i;
    for (i = 0; keyword[i] != NULL; i++)
        if (!strcmp(s, keyword[i]))
            return 1;
    return 0;
}