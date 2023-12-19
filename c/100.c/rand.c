#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
int main() {
    int a, i, b;
    srand((unsigned)time(NULL));
    while(i<20)
    {
        i++;
        a = rand()%MAX+1;  //限制在1-MAX
        b = rand();      //完全随机
        printf("%d\t%d\n",a,b);
    }
    return 0;
}
