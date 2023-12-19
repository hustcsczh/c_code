#include <stdio.h>

enum DAY
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} weekend;

int main()
{
    weekend = /*(enum DAY)可要可不要*/ MON;
    printf("day is %d\n", weekend);
    // 遍历枚举元素
    while (weekend <= SUN)
    {
        printf("枚举元素：%d \n", weekend);
        // weekend=(enum DAY)/*一定要*/(weekend+1);
        weekend++;
    }
}