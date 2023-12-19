#include <stdio.h>
#include <stdlib.h>


/*
fp=fopen(filename,"way")  int fputc (char ch,FILE* fp)      int  fgetc(int ch,FILE* fp)
文件打开                      字符写入  成功返回0                字符读取 成功返回0

int fclose(fp)      int fputs(const char*s FILE* fp)     char* fgets(char *s,int n,FILE* fp)
文件关闭  成功返回0        字符串写入  成功返回0             字符串读取n-1个 成功返回指针  

int fprintf(FILE* fp,const*char* format,....)  写入   返回值为输入项数否则EOF
int fscanf(FILE* fp,cons char* format,.....)   读取   返回值为读取个数否则EOF

二进制文件读写
size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t n,FILE *stream);
typedef unsigned int size_t;
*/
int main() {
    const char* filename = "D:\\code  vs\\c\\a.txt";
    FILE *fp;
    char ch;
    char s[20];

//只读
    if ((fp = fopen(filename, "w+")) == NULL) {
        printf("Can't open the file!");
        exit(-1);
    }
    while ((ch = fgetc(fp)) != EOF) {
       putchar(ch);//每读取一个字符，文件指针向后移动一位//读完指针自动回到首位
    }
    printf("%\n");
    fclose(fp);
//写入字符串
    if ((fp = fopen(filename, "w" )) == NULL) {
        printf("Can't open the file!");
        exit(-1);
    }
    gets(s);
    fputs(s, fp);
    fclose(fp);//owrite

//添加字符串 
    if ((fp = fopen(filename, "a" )) == NULL) {
        printf("Can't open the file!");
        exit(-1);
    }
    gets(s);
    fputs(s, fp);
    fclose(fp);//oadd
//只读
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Can't open the file!");
        exit(-1);
    }
    while ((ch = fgetc(fp)) != EOF) {
       putchar(ch);//每读取一个字符，文件指针向后移动一位
    }
    fclose(fp);
    printf("%\n");
    return 0;
}
