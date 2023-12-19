#include <stdio.h>
void Monthday(int year, int yearday, int *pmonth, int *pday);
int main()
{
    int year, month, day, yearday;
    printf("input the year and day of the year :");
    scanf("%d%d", &year, &yearday);
    Monthday(year, yearday, &month, &day);
    printf("it is the %d month and %d day in %d.\n", month, day, year);
    return 0;
}
void Monthday(int year, int yearday, int *pmonth, int *pday)
{
    static int daytab[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                               {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int i, leap;
    leap = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
}





// 反向求，且非指针版
/********** Begin **********/
#include <stdio.h>
void Monthday(int year, int month, int day);
int yearday;
int main()
{
    int year, month, day;
    // printf("input the year and day of the year :");
    scanf("%d %d %d", &year, &month, &day);
    Monthday(year, month, day);
    printf("%d\n", yearday);
    return 0;
}
void Monthday(int year, int month, int day)
{
    extern int yearday;
    static int daytab[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                               {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int leap;
    leap = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    for (int i = 1; i <= month; i++)
    {
        yearday += daytab[leap][i - 1];
    }
    yearday += day;
}

/**********  End **********/
