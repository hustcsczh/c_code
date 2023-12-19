#include <stdio.h>
#include <string.h>

int main() {
    int c = 0;
    char str[7];
    char name[20];
    scanf("%6s", str);
    if (strcmp(str, "type_c") == 0) {
        scanf("%s", name);
        if (strcmp(name, "/p") == 0) {
            c = 1;
        }
    } else {
        printf("指令错误");
        return 0;
    }

    FILE* fp;
    int i = 1;
    char s[100] = {'\0'};
    fp = fopen("src/step1_1/test1.c", "r");
    if (c==0) {
        int ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
    } else {
        while (fgets(s, 100, fp) != NULL) {
            printf("%d ", i);
            printf("%s", s);
            i++;
            if (i % 10 == 1) {
                i = 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
