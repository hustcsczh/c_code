#include <stdio.h>
int main()
{
    int a[10] = {0};
    int count = 0, sum = 0;
    int i = 0;
    while (count < 10)
    {
        int x;
        scanf("%d ", &x);
        if (x > 99 && x < 201)
        {
            a[i] = x;
            count++;
            i++;
        }
    }
    int max_high = 0;
    scanf("%d", &max_high);
    for (int i = 0; i < 10; i++)
    {
        if (max_high + 30 >= a[i])
        {
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}
