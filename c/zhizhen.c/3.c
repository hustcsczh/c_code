#include <stdio.h>
void bubblesort(int x[], int);
int main()
{
    int x[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubblesort(x, 10);
    for (int i = 0; i < 10; i++)
        printf("%d", x[i]);
    return 0;
}
void bubblesort(int x[10], int n)
{
    int i, t, *p;
    for (i = 0; i < (n - 1); i++)

    {
        for (p = x; p < x - i + n - 1; p++)
        {
            if (*p > *(p + 1))
            {
                t = *p;
                *p = *(p + 1);
                *(p + 1) = *p;
            }
        }
    }
}