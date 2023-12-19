#include <stdio.h>
#include <math.h> //孪生素数

int is(int x);

int main()
{
    long long m;
    scanf("%lld", &m);
    long long M[m + 1];

    for (int i = 1; i < m + 1; i++)
    {
        M[i] = i;
    }

    for (int i = 2; i < m + 1; i++)
    {
        if (M[i] == 0)
        {
            continue;
        }
        if (is(M[i]) == 1)
        {
            for (int j = M[i] + 1; j < m + 1;)
            {
                if (M[j] == 0)
                {
                    j++;
                    continue;
                }
                if (j % M[i] == 0)
                {
                    M[j] = 0;
                }
                j++;
            }
        }
        else
        {
            M[i] = 0;
        }
    }

    for (int i = 2; i < m - 1; i++)
    {
        if (M[i] != 0 && M[i + 2] != 0)
        {
            printf("(%lld,%lld)", M[i], M[i + 2]);
        }
    }
    return 0;
}

int is(int x)
{
    if (x == 2)
    {
        return 1;
    }
    for (int i = 2; i < sqrt(x) + 1; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
