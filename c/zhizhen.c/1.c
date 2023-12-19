
#include <stdio.h>

int main()
{

    char *str_arr[] = {"hello", "world", "C"};//不可改变

    int i;

    for (i = 0; i < 3; i++)
    {
        printf("%s\n", str_arr[i]);
    }

    return 0;
}
