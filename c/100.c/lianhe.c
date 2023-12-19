#include <stdio.h>
#include <stdlib.h>             //联合
void f0(int b), f1(int b), f2(int b), f3(int b), f4(int b), f5(int b), f6(int b), f7(int b);
void (*p_fun[8])(int b) = {f0, f1, f2, f3, f4, f5, f6, f7};   //函数指针数组
struct w_bits
    {
        unsigned short bit0 : 1, bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1;
    };
 union w{
        short i;
        struct w_bits bit;
 };
int main()
{
    unsigned short n;
    scanf("%hu", &n);
    union w x= {n};
    if(x.bit.bit0==1)
        (*p_fun[0])(0);
    if(x.bit.bit1==1)
        (*p_fun[1])(1);
    if(x.bit.bit2==1)
        (*p_fun[2])(2);
    if(x.bit.bit3==1)
        (*p_fun[3])(3);
    if(x.bit.bit4==1)
        (*p_fun[4])(4);
    if(x.bit.bit5==1)
        (*p_fun[5])(5);
    if(x.bit.bit6==1)
        (*p_fun[6])(6);
    if(x.bit.bit7==1)
        (*p_fun[7])(7);
    return 0;  
}
void f0(int b)
{
    printf("the function %d is called!\n",b);
}
void f1(int b)
{
    printf("the function %d is called!\n",b);
}
void f2(int b)
{
    printf("the function %d is called!\n",b);
}
void f3(int b)
{
    printf("the function %d is called!\n",b);
}
void f4(int b)
{
    printf("the function %d is called!\n",b);
}void f5(int b)
{
    printf("the function %d is called!\n",b);
}void f6(int b)
{
    printf("the function %d is called!\n",b);
}void f7(int b)
{
    printf("the function %d is called!\n",b);
}