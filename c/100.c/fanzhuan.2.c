// 字符串反转，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。
#include <stdio.h>
#include <string.h>
void fanzhuan(char *s);
int main()
{
    char s[100];
    gets(s);
    fanzhuan(s);
    return 0;
}
void fanzhuan(char *s)
{
    char *p = s + strlen(s) - 1;
    for (; p >= s; p--)
        printf("%c", *p);
}

/*#include <stdio.h>
#include <string.h>
void fanzhuan(char *s);
int main()
{
    char s[100];
    gets(s);
    fanzhuan(s);
    return 0;
}
void fanzhuan(char *s)
{
    for (char *p = s + strlen(s) - 1; p >= s; p--)
    {
        printf("%c", *p);
    }
}*/