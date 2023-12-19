#include <stdio.h>
#include <stdbool.h>
#define WAY compareByScore    //在此处决定以何种方式排序；

typedef struct student
{
    char name[20];
    int age;
    float score;
} Student;
bool compareByAge(Student stu1, Student stu2);
bool compareByScore(Student stu1, Student stu2);

void sortStudents(Student *array, int n, bool (*p)(Student, Student));
void print(Student *array, int n);

int main()
{
    char s[10];
    Student stu1 = {"小明", 19, 98};
    Student stu2 = {"小红", 20, 78};
    Student stu3 = {"小白", 21, 88};
    Student stuArray[3] = {stu1, stu2, stu3};
    sortStudents(stuArray, 3, WAY);
    print(stuArray, 3);
    return 0;
}

bool compareByAge(Student stu1, Student stu2)
{
    return stu1.age > stu2.age;
}

bool compareByScore(Student stu1, Student stu2)
{
    return stu1.score > stu2.score;
}

void sortStudents(Student *array, int n, bool (*p)(Student, Student))
{
    Student temp;

    int flag = 0; //标记作用。在排序过程中，如果在一轮遍历中没有发生交换操作，即数组已经有序，就可以提前结束排序，减少不必要的比较次数，提高效率。

    for (int i = 0; i < n - 1 && flag == 0; i++)
    {
        flag = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p(array[j], array[j + 1]))//函数指针的调用，这里的array不用区分类型，，因为宏定义中确定了比较的数据，函数指针p指向该数据增强了可用性；
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                flag = 0;//表明已经进行了排序，若一次都没有则flag为1；直接结束排序，说明一开始就是有序的
            }
        }
    }
}

void print(Student *array, int n)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s, Age: %d, Score: %.2f\n", array[i].name, array[i].age, array[i].score);
    }
}
