#include <stdio.h>
#include <string.h>

void reverseStr(char *str);

int main()
{
    char str[20];
    printf("输入一个字符串    :");
    scanf("%s", str);
    printf("翻转之后的字符串为:");
    reverseStr(str);
    return 0;
}

void reverseStr(char *str)
{
    if (*str == '\0')
        return;
    reverseStr(str + 1);//检索到最后一位后退出递归开始从过后往前输出；
    printf("%c", *str);
}
