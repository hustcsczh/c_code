#include"4.h"
#define D(x)  (x)*(x)
#define D1(x)  ((x*x))
int a = 3;
#define R 3
#define W 4
#undef MAX    //防止在其他文件里定义了MAX
#define MAX 25

int main()
{
    int i = 0;
    extern int a;                        //这里的a是外面定义的a值
    printf("%d\n", a);
    srand((unsigned)time(NULL));
    while(i<3)
    {
        i++;
        a = rand()%MAX+1;  //限制在1-MAX
        printf("第%d次随机数的值为%d\n",i,a);
    }
#ifdef DEBUG
    printf("正在调试\n");
#endif
    extern int a;
    printf("a=%d\n",a);          //这里的a是最后一次得到的随机值
    printf("%d\n", 27 / D(3));    //27    //实际上是27/3*3   并不是27/(3*3)由于只是进行了简单的替换
    printf("%d\n", 27 / D1(3));    //3
#ifdef MAX
    printf("定义了MAX=%d\n", MAX);
#else
    printf("未定义");
#endif

#if W       //只能是整型
    printf("%d\n", W);
#elif R
    printf("%d\n", W);
#endif
}

/*
//1.随机数的产生
//2.auto      static      extern
//  int       静态变量       拓展作用范围
//3  全局变量   static     静态全局变量，在外声明，但只作用于声明所在文件
//             extern     全局变量    引用时加extern,扩大使用范围
//4 带参数的宏   要加括号  #define  #undef 
//5 条件编译   #ifdef    #eldef   #endif   使生成的目标程序更短//便于DEBUG调试
//6 断言  不考
//7
*/
