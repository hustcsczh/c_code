#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                   /*  *arr(直接用数组名)++   非法    */
int two_find(int *, int, int,int);
int main()
{
    int n;
    scanf("%d", &n);
    int A[11] = {1, 2, 3, 4, 5,7,8, 9, 10,11,12};
    int b = two_find(A, 0, 9, n);
    if(b)
    {
        printf("在第%d位", b);
    }
    else
        printf("不存在");
//二维数组
	int a[2][3] = { {1,2,3},{4,5,6}};
	int(*p)[3] = (void *)&a[0][0] ;           
	int *q=(void *) &a[0][0];             
	printf("%p\n", p+1);     
	printf("%p\n", q+1);     
}

    //*a相当于首行首元素地址
    //*(*a + i)//二维数组中，可以依次访问到第1行的每一个元素；
    //*(*(a + j) + i)//二维数组中，可以依次访问到每一行的每一个元素   j+1行i+1列

    /*所以对于二维数组传参时:
    传递a其实相当于传递了第一行的地址，它的类型是int (*a)[5]
    传递&a其实相当于传递整个数组的地址，它的类型是int (*a)[3][5]*/
    //虽然数值一样，但是+1之后一个换行，一个直接结束数组
int two_find(int *a, int left, int right,int x)
{
    int mid = (left + right) / 2;
    while (left<=right)
    {
        if (a[mid] == x)
            return mid;
        else if(x>a[mid])
        {
            return two_find(a, mid+1, right, x);
        }
        else if(x<a[mid])
        {
            return two_find(a, left, mid-1, x);
        }
    }
    return 0;
}