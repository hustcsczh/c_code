#include <stdio.h>

struct student
{
    int num;
    char name[12];
    double score;
};

void scan(struct student *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %lf", &(p[i].num), p[i].name, &(p[i].score)); //  p[i].name 本身可以看做数组，不需要&
    }
}

void print(struct student *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d %s %.1lf\n", p[i].num, p[i].name, p[i].score);
    }
}

int main()
{
    struct student s[3];
    scan(s, 3);
    print(s, 3);
    return 0;
}
