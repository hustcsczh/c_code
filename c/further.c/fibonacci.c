#include <stdio.h>
int fibonacci_sum(int x)
{
    int a = 0,
        b = 1,
        c = 0;
    if (x == 1)
        return 1;
    if (x == 0)
        return 0;
    while (x >= 2)
    {
        c = a + b;
        a = b;
        b = c;
        x--;
    }
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += fibonacci_sum(i);
    }
    printf("%d", sum);
    return 0;
}
