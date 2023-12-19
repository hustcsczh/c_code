#include <stdio.h>
#include <string.h>

struct students
{
    char name[20];
    int cj;
};
void scan(struct students *p, int N); // 读入
void sort(struct students *p, int N);//排序
void print(struct students *p, int N);//输出

int main(void)
{
    
    int n;
    scanf("%d", &n);
    struct students S[n];
    scan(S, n);  
    sort(S, n);
    print(S, n);
    return 0;
}


void sort(struct students *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (p[j].cj < p[j + 1].cj)
            {
                struct students temp = p[j];//交换一整个结构体，而不是其中的元素
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            else if (p[j].cj - p[j + 1].cj == 0)//成绩相等比名字首字母，次字母。。。。。
            {
                int k = 0;
                while (p[j].name[k] == p[j + 1].name[k])
                {
                    k++;
                }
                if (p[j].name[k] > p[j + 1].name[k])//[k]表示第几个字符
                {
                    struct students temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
    }
}

void scan(struct students *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d", p[i].name, &(p[i].cj));
    }
}

void print(struct students *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", p[i].name, p[i].cj);
    }
}
