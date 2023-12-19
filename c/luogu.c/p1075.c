#include <stdio.h>
#include <math.h>
int isprime(int i);

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 2; i < sqrt(n); i++)
    {
        if (isprime(i) && (n % i == 0))
        {
            m = i;
            break;
        }
    }
    printf("%d", n / m);

    return 0;
}
int isprime(int i)
{
    int q = 1;
    for (int j = 2; j < sqrt(i); j++)
    {
        if (i % j == 0)
        {
            q = 0;
            break;
        }
    }
    return q;
}
