#include <stdio.h>
int rrr(char *arr);
int main()
{

    char arr[100];
    scanf("%s", arr);

    printf("\n%d", rrr(arr));
    return 0;
}
int rrr(char *arr)
{
    printf("%p\n", arr);
    char *start = arr; // 这里指针的定义中也只能是char，同类型才能加减
    printf("%p\n", start);
    while (*arr != '\0')
    {
        arr++;
        printf("%p\t", arr); // 相邻元素的地址相差1;
    }

    return (arr - start); // 求子符串长度
}