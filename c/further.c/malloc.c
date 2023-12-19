#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5
#define LEN 4
//指针数组表量；表示方式像指针+数组
void write(char *[],int);
void strsort(char *[],int);

int main()
{
    int len, i;
    char* s[LEN], temp[MAX];
    printf("请输入%d个字符串 每行一个:\n",LEN);
    for (i = 0; i < LEN;i++)
    {
        gets(temp);
        len = strlen(temp);
        s[i] = (char *)malloc(len + 1);//动态分配内存
        if(s[i]==NULL)//如果分配失败
            return -1;//就返回-1
        strcpy(s[i] ,temp);
    }
    strsort(s, LEN);
    write(s, LEN);
    return 0;
}


//字符串的冒泡排序；指针数组；直接交换指针提高效率
void strsort(char *str[], int size)//str是指针数组，str[i]表示指针//或者改写为二级指针
{
    char *temp;
    int i, j;
    for (i = 0; i < size - 1;i++)
    {
        for (j = 0; j < size - 1 - i;j++)
        {
            if(strcmp(str[j],str[j+1])>0)
            {
                temp = str[j];//指针交换位置；
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
            //puts(str[j]);//str[i]就表示一个指针，指针指向一个数组的首地址，这样就可以直接输出字符串
            //puts(str[j + 1]); // （接上）类似于  char s[20];puts(s);
        }
    }
}

void write(char** p/*char* p[]*/, int n)//这里指针数组也可以改写为二级指针
{
    int i = 0;
    while (n-- > 0)
        printf("%s\n", *p++/*p[i++]*/);
}
