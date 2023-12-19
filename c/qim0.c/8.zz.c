#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
#define MAX 25
void strsort(char **s, int n);
int main()
{
    char s[] = {"hello world"};
    char *p;
    p = s;
    while(p-s<strlen(s))
        printf("%c", *p++);
    printf("\n");
    int i;
    char *S[N], t[MAX];
    for(i=0;i<N;i++)
    {
        gets(t);
        S[i] = (char *)malloc(strlen(t)+1);
        strcpy(S[i],t);
    }
    strsort(S,N);
    for(i=0;i<N;i++)
        printf("%s\n", S[i]);
    return 0;
    //高精度计算
}

/*
//常量指针             指向常量的指针              int a=2;  const int* p;  p=&a;      即p的所指向的值不能通过p修改
//指针常量             指针的类型是常量            int a=2;  int* const p=&a;          即p的指向不能修改（地址限定）   必须在定义时初始化
//指向常量的指针常量    指针和所指都是常量          int a=2;  const int* const p=&a     什么都改不了   必须在定义时初始化
*/
void strsort (char** s , int n)
{
    char *temp;
    int i, j ;
    for(i=0; i<n-1; i++)
    for(j=0; j<n-i-1; j++)
    if ( strcmp(s[j],s[j+1] ) >0 )
    {
        temp=s[j];
        s[j]=s[j+1];
        s[j+1]=temp;
        /*
        temp=*(s+j);
        *(s+j)=*(s+j+1);
        *(s+j+1)=temp;
        */
    }
}


