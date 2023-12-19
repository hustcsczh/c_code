#include <stdio.h>
void paixu(int a[], int b);
int chazhao(int a[], int x, int num);

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    paixu(a, n);//冒泡排序
    int x;
    printf("请输入你要查找的数字x:");
    scanf("%d", &x);
    if (chazhao(a, x, n) >= 0)
        printf("找到了，在排完序后的%d位", chazhao(a, x, n) + 1);
    else
        printf("没找到");
    return 0;
}

void paixu(int a[], int b)
{
    for (int i = 0; i < b - 1/**/; i++)
    {

        for (int j = 0; j < b - i - 1/**/; j++)
        {
            if (a[j] > a[j + 1]) // 冒泡排序
            {
                int t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
}

int chazhao(int a[], int x, int num)
{
    int l = 0, r = num - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (x == a[m])
        {
            return m;
        }
        else if (x < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m - 1;
        }
    }
    return -1;
}
/*#include <stdio.h>

void paixu(int *a, int b);
int chazhao(int a[], int x, int num);

int main()
{
    int n;
    printf("请输入数组的长度n: ");
    scanf("%d", &n);
    int a[n];
    printf("请输入数组的元素: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    paixu(a, n);
    // 开始二分查找；
    int x;
    printf("请输入你要查找的数字x: ");
    scanf("%d", &x);
    int result = chazhao(a, x, n);
    if (result == -1)
    {
        printf("未找到数字%d\n", x);
    }
    else
    {
        printf("数字%d在数组中的位置为%d\n", x, result);
    }

    return 0;
}

void paixu(int *a, int b)
{
    for (int i = 0; i < b - 1; i++)
    {

        for (int j = 0; j < b - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
}

int chazhao(int a[], int x, int num)
{
    int l = 0, r = num - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (x == a[m])
        {
            return m;
        }
        else if (x < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}*/