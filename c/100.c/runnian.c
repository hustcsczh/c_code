
#include <stdio.h>

// 定义日期结构类型
typedef struct {
    int year;
    int month;
    int day;
} Date;

int dayyear(Date date) {
    int daysmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 判断是否为闰年
    if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)) {
        daysmonth[1] = 29;
    }
    
    // 判断日期是否合法
    if (date.month < 1 || date.month > 12 || date.day < 1 || date.day > daysmonth[date.month - 1]) {
        return -1;
    }
    
    int total_days = 0;
    
    for (int i = 0; i < date.month - 1; i++) {
        total_days += daysmonth[i];
    }
    
    total_days += date.day;
    
    return total_days;
}

int main() {
    Date date;
    scanf("%d %d %d", &date.year, &date.month, &date.day);
    
    int result = dayyear(date);
    
    if (result == -1) {
        printf("不存在这样的日期\n");
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}
