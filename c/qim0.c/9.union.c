//定义一个data共用体
#include<stdio.h>
union data{
    int n;
    char ch;
    short m;
};
 
int main(){
     
    //创建一个共用体变量a   默认为小端模式，高位在高地址
    union data a;
    printf("a.size = %d, data.size = %d\n", sizeof(a), sizeof(union data) );
    //对成员a赋值
    a.n = 0x40;
    printf("n = %#X, ch = %c, m = %#hX\n",  a.n, a.ch, a.m);
    //对成员b赋值
    a.ch = '9';
    printf("n = %#X, ch = %c, m = %#hX\n", a.n, a.ch, a.m);
    //对成员c赋值
    a.m = 0x2059;
    printf("n = %#X, ch = %#X, m = %#hX\n", a.n, a.ch, a.m);
   //再对成员a赋值
    a.n = 0x3E25AD54;
    printf("n = %#X, ch = %#X, m = %#hX\n", a.n, a.ch, a.m);

    union U{long a;
        short b;
        char c;
        char s[20];
    } v = {0x01020304}, *p = &v;
    printf("%d    %d    %d    %d\n", p->s[0],sizeof(v),v.c,v.b);

    return 0;
}