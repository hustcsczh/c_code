#include <stdio.h>
#include <stdlib.h>


int main() {
    const char* filename = "D:\\code  vs\\c\\goods.txt";
    FILE *fp;
    char ch;
    char s[20];

//读写
    if ((fp = fopen(filename, "r+")) == NULL) {
        printf("Can't open the file!");
        exit(-1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
       putchar(ch);//每读取一个字符，文件指针向后移动一位//这里读完指针不会自动回到首位r+
    }
    printf("%\n");
    gets(s);
    fputs(s, fp);
    fclose(fp);

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Can't open the file!");
        exit(-1);
    }
    fgets(s, 20, fp); // fgets函数返回值是个指针：
    puts(s);
    return 0;
}
