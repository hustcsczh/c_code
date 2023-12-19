#include <stdio.h>
#include <string.h>
void reverseString(char *str);

int main()
{
    char str[100];
    scanf("%s", str);
    reverseString(str);
    printf("%s\n", str); // 输出：olleh //改变了原字符数组
    return 0;
}

void reverseString(char *str)
{
    char *start = str;
    char *end = start + strlen(str)-1; // 指向字符串最后一个字符的下一个位置
    char temp;
    // 开始反转字符串
    while (start < end)
    {
        // 交换开始和结束位置的字符
        temp = *start;
        *start = *end;
        *end = temp;
        // 移动指针
        start++;
        end--;
    }
}