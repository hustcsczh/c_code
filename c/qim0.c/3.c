#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    
    int a = 23;
    float b = 3.48;
    printf("%010.4f \n%-10.4f \n%f \n%g \n", b,b,b,b);
    printf("%.1f\n",b); //浮点数可以四舍五入
    float g;            // double  scanf()只能是%l  大写Lf也不行；//输出无所谓
    scanf("%4f", &g); // 输入c  2.159845  //只读取前4位2.15  后面全补0;
    printf("%f\n", g);// 2.150000
    int e= 1;
    printf("%d, %d, e = %d\n", (e*=2), (e+=3), e);  
    //结果是8 8 8
    //printf 压栈是从右至左的。
    /*解析:
    根据从右向左的执行顺序，a的值最终会变成8。那么表
    这三个表达式展开来看分别是 a = a* 2:a = a + 3:a。
    达式本身的值是多少?是表达式左值的引用，也就是三个表达式的值最后其实都是取 a 的值。*/
    return 0;
}

/*
//        o    x/X    d/i      e/E         f         g/G     
//     八进制  十六    int   科学计数法    6位小数   不输出无效0(<=6位)
*/