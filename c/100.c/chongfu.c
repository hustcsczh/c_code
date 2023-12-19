#include <stdio.h>
#include <string.h>
void RemoveDuplicate(char *s);
int main()
{
    char str[200];
    while (fgets(str, 200, stdin) != NULL)
    {
        RemoveDuplicate(str);
        printf("%s", str);
    }
    return 0;
}
void RemoveDuplicate(char *s)
{
    char *b = s;
    int r, w, len;
    len = strlen(s);
    int a[256] = {0};
    for (r = 0; r < len; r++)
    {
        int t;
        t = (int)(s[r]);
        if (a[t] > 0)
        {
            a[t]++;
        }
        else
        {
            a[t] = 1;
        }
    }
    // 移除重复字符并将后面的字符往前移动
    for (r = w = 0; r < len; r++)
    {
        int t;
        t = (int)(b[r]);
        if (a[t] == 1)
        {
            b[w++] = b[r];
        }
        else if (a[t] > 1)
        {
            b[w++] = b[r];
            a[t] = 0;
        }
    }
    b[w] = '\0'; // 添加字符串结束符
}
