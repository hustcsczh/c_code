// 函数指针；顾名思义就是指向函数的指针，参数类型相同；
#include <stdio.h>
 // 这里一定要有()表示优先级使类型为指针，否则为指针函数；参数名可去；
int my_function(int x, int y);
int main()
{
    int (*func_ptr)(int, int)=my_function;
    // 函数指针赋值
    int ret = (*func_ptr)(1, 2);
    // 通过函数指针来调用函数
    // 或ret = func_ptr(1, 2)
    // 前面的(*  )要不要无所谓；
    printf("ret =%d\n", ret);
    return 0;
}
int my_function(int x, int y)
{
    return x+y;
}


/*
// 指针函数：返回型为指针的函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* fun(int , int );//这里不需要(),表明为指针函数；
int main()
{
    int* p1= NULL;
    p1= fun(1, 9);//函数返回类型是指针，给p1赋值；
    printf("*p1 = %d \n",*p1);
    return 0;
}

int* fun(int a, int b)
{
    int *p = NULL;
    int c=(a + b);
    p = &c;
    return p;
}*/
