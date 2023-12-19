/*30 个人在一条船上，超载，需要 15 人下船。
是人们排成一队，排队的位置即为他们的编号。
报数，从 1 开始，数到 9 的人下船。
如此循环，直到船上仅剩 15 人为止，问都有哪些编号的人下船了呢*/
#include <stdio.h>
int main()
{
    int a[30] = {0};
    int i = 0, c = 0, count = 0;
    while (count < 29)
    {
        if (a[i] == 0)
        {
            c++;
        }
        if (c == 9)
        {
            c = 0;
            a[i] = 1;
            printf("%d\t", i + 1);
            count++;
        }
        i++;
        if (i == 30)
            i = 0;
    }
    return 0;
}
