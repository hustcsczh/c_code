#include <stdlib.h>
#include <stdio.h>

int get(void);                                                       // 获得随机值
void populate_array(int *array, size_t arraySize, int (*get)(void)); // 将随机值赋给数组
int main(void)
{
    int myarray[10];
    /* get 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myarray, 10, get); // 调用函数 ；
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myarray[i]); // 遍历数组，输出值；
    }
    return 0;
}
void populate_array(int *array, size_t arraySize, int (*get)())
{
    for (size_t i = 0; i < arraySize; i++)
        array[i] = get();
}
int get()
{
    return rand();
}