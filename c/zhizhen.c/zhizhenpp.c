#include <stdio.h>
int main()
{
    int a = 4;
    int *p;
    p = &a;
    int **p1;
    p1 = &p;
    int ***p2;
    p2 = &p1;
    printf("%d %p %d %p %d %d %p %d %d %d", a, p, *p, p1, *p1, **p1, p2, *p2, **p2, ***p2);

    return 0;
}