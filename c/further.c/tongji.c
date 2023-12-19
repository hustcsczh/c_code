#include <stdio.h>
int main()
{
    char c;
    int ch = 0, zi = 0, rows = 0;
    int tiaoguo = 0, chnum = 0;
    while ((c = getchar()) != EOF)
    {
        if (rows == 0) // 只在第一次使用
            rows++;

        if (c == ' ' || c == '\t') // 空白不计入
        {
            zi++;
            continue;
        }

        if (tiaoguo == 3) // 处理了前一个汉字，直接跳入下一个字符
        {
            tiaoguo = 0;
            continue;
        }

        if (c == '\n' || c < 0) // 换行，汉字
        {
            if (chnum == 1)
                zi++;
            chnum = 0;
            if (c < 0)
            {
                zi++;
                ch++;
                tiaoguo = 3; // 表示每一个汉字已经处理了一位，直接跳过
            }
            if (c == '\n')
            {
                rows++;
            }
            continue;
        }
        // 此时处理字母
        ch++;
        chnum = 1;
        tiaoguo = 0;
    }
    /*if (chnum == 1)
       ch++;*/
    printf("字数 %d\n字符数 %d\n行数 %d", zi, ch, rows);
    return 0;
}