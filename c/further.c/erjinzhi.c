
#include <stdio.h>
int main()
{
    int b[32] = {0};
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 32; i++)
    {

        b[32 - i - 1] = (n >> i) % 2;
    }
    for (int i = 0; i < 32; i++)
    {
        b[i] = b[i] < 0 ? -b[i] : b[i];
        printf("%d", b[i]);
        if (i % 4 == 3)
            printf(" ");
    }
}