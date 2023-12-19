// assert.c
#include <stdio.h>
#include <assert.h>

int main()
{
    double x, y, z;
    puts("Enter X and Y (X > Y): ");
    while (scanf("%lf%lf", &x, &y) == 2)
    {
        z = x - y;
        assert(z >= 0);
        puts("OK\nEnter X and Y (X > Y): ");
    }
    return 0;
}
