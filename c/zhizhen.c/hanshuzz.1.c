#include<stdio.h>
#define N 5
#define NUM 60
#define WAY less
//代码更加灵活，便于修改操作
int G(int, int);
int less(int, int);//定义两个函数指针

void findNumber(int *, int,  int (*)(int, int));//函数参数为函数指针
int main()
{
    int score[N];
    for (int i=0; i < N;i++)
    {
        scanf("%d", score + i);
    }
    findNumber(score,NUM, WAY);
    return 0;
}

void findNumber(int *x,int compN,int(*p)(int,int))
{
    for (int i = 0; i < N;i++)
    {
        if(p(x[i],compN))
            printf("%d", x[i]);
    }
}

int G(int number, int compN)
{
    return number > compN ? number : 0;
}
int less(int number, int compN)
{
    return number > compN ? number : 0;
}