
#include <stdio.h>

struct peo
{
    char name[20];
    char tele[12];
    char sex[5];
    int high;
};

struct st
{
    struct peo *p; // 结构体里包含结构体指针
    int num;
    float score;
};

int main()
{
    struct peo p1 = {"张三", "127648480", "男", 181};
    printf("%s %s %s %d\n", p1.name, p1.tele, p1.sex, p1.high);

    struct st p2 = {&p1, 1, 3.14}; // 优先使用指针；节约空间和时间
    printf("%s %s %s %d %f\n", p2.p->tele, p2.p->sex, p2.p->name, /*搭配指针*/ p2.num, p2.score);
    ///////////////////////////这里并不是被包含的那个结构体变量的名称，而是看住结构体里
    return 0;
}
