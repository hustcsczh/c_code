#include <stdio.h>
float max(int c ,int d)
{
    return c + d;    //return 里面是整形,返回值类型以函数定义时为标准；
}
int main()
{
    int a=2;
    int b=5;
    printf("1.0\t%d\n", max(a, b));
    printf("2.0\t%f %f\n", 2E1, 2.5E1);
    printf("3.0\t%d %c\n",3,'c');     //    /a  蜂鸣器发声 什么都不显示
    printf("4.0\t\\an\a\n");          //输出\an  经过转义
    printf("5.0\t%s\n", "\\an\a");    // 输出\\an\a   原样输出
    //int c=d=3;  // 错误形式定义
    int c,d; int e= d =c= 3; //合法形式  连续赋值只定义一个；
    printf("6.0\t%d %d %d\n", e, d,c);
    printf("7.0\t%d %d\n", -a++,a);   //-和++优先级相同但是右结合，相当于-(a++)
    int x=2;
    printf("8.0\t%d %d\n", x = c - 2 ? 5 : c - 3,x);//? :先计算再赋值；
    printf("9.0\t%d\n", (b=4,c = 7));//结果为7，逗号表达式
    printf("10.0\t%d\n", b=4,c = 7);  //结果为4，第一个式子的值
    printf("11.0\t%d\t%d\n", -15 >> 3,1>>1);   // 结果为-2说明我的电脑负数右移高位补1;//所以右移通常为无符号数字
    printf("12.0\t%f\n", (float)5 / 2);     //5.00000/2  ->2.500000
    printf("13.0\t%f\n", (float)(5 / 2));     //  (float)2->2.000000
}
/*
1.关键字
2.标识符
3.指数形式可以无小数点  10E(e)2   2.1E4  2.E4  2E4
4.转移序列，字符常量   'a'   '&'   \n  \t   '和\ 只能用转移序列打印  \'单引号    \\反斜杠
5.优先级   单目>双目    所有+ -  都是同一优先级  ++ -- + -
6.运算符
7.位运算  
//        char   short   int   long   long_long    unsinged_ char    _short   _int   _long    _long_long
//        1        2      4     4       8位
//        %c       %h     %d   %ld      %lld                 %d     %hu      %u     %lu       %llu
//
//     ~按位取反         &按位与          |按位或               ^按位加(异或)
//     0->1  1->0        有0则0(盖0)      有1则1(盖1)           相加不进位
//     x = x ^ ((1 << n) - 1) << (p+1-n)     <<优先级高于^   将x的p位开始向右n为取反(可以看做将这n位按位加1)
//
8.类型转换
//8.1算数转换  char*long+double        char->int->long   long*long->double    double+double
//8.2赋值转换   short a=2; double b=3.4  ; a=b;   转换类型取决于赋值左式，b->short 3.4->3   a=3;//会报错；
9.枚举类型
*/