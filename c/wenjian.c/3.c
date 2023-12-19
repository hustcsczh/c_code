#include<stdio.h>
#include <stdlib.h>
void data_write(char *); /* 数据采集并存盘*/
void data_cal(char *); /*从文件读入数据并进行计算*/


int main(void)
{
    char *a ="D:\\code  vs\\c\\goods.txt";
    data_write(a);
    data_cal(a);
    return 0;
}
void data_write(char * filename)
{
    FILE *out;
    char name[20];
    int number;
    float price;
    if((out = fopen(filename,"w")) == NULL)
        exit(-1);
    printf("input name number and price please!\n");
    while(scanf("%s %d %f", name,&number,&price)!=EOF)
        fprintf(out, "%s %d %f\n", name, number,price);
    fclose(out);
}

void data_cal(char * filename)
{
    FILE * in;
    char name[20];
    int number;
    float price;
    if((in = fopen(filename,"r")) == NULL)
        exit(-1);
    while(fscanf(in, "%s %d %f" ,name,&number,&price)!= EOF)
    {
        printf("%s\t %d\t %.2f\n",name,number,price*number);
    }
        fclose(in);
}