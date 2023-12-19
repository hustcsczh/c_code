#include <stdio.h>

void strcate(char *s, char *t);
void strdecl(char[], char);

int main()
{
    char a[20];
    char b[20];
    char c;
    // printf("%s   %s\n", b, a)
    scanf("%s %s %c", b, a, &c);
    strcate(b, a);
    printf("%s\n", b);
    strdecl(b, c);
    printf("%s", b);
    return 0;
}

void strcate(char *s, char *t)
{
    while (*s)
    {
        s++;
    }
    while (*t)
    {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}

void strdecl(char str[], char c)
{
    int point = 0; // 字符串位置标号，用于保存当前有效字符位置
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            continue; // 若当前字符为要删除的字符，则直接跳过继续进行循环
        }
        else
        {
            str[point] = str[i]; // 当前字符为非删除字符，则往前覆盖
            point++;             // 有效字符标号位置递增
        }
    }
    str[point] = '\0'; // 循环结束，最后一个字符为结束符
}
