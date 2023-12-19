
#include <stdio.h>

int main()
{
    int l, m;
    scanf("%d %d", &l, &m);
    int a[l + 1];
    for (int i = 0; i < l + 1; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int num[m][2];
        scanf("%d %d", &num[i][0], &num[i][1]);
        for (int j = num[i][0] - 1; j <= num[i][1] - 1; j++)
        {
            a[j] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < l + 1; i++)
    {
        if (a[i] == 0)
            // printf("%d\n", i);
            sum++;
    }
    printf("%d", sum);

    return 0;
}
