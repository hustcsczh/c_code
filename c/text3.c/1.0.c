#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct score{
    int date;
    struct score *next;
};

struct stu{
    char xuehao[20];
    char name[10];
    struct score *S;
};

void g1(int n)
{
    struct stu s[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s", s[i].xuehao, s[i].name);
        s[i].S = (struct score *)malloc(sizeof(struct score));
        createlist(&(s[i].S));
    }
};

void createlist(struct score **head)
{
    struct score *tail = *head;
    int a;
    for (int count = 0; count < 4; count++) 
    {
        scanf("%d", &a);
        tail->next = (struct score *)malloc(sizeof(struct score));
        tail = tail->next;
        tail->date = a;
        tail->next = NULL;
    }
};

print(struct stu *s)
{

};
int main()
{
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        int x;
        scanf("%d", &x);
        g1(x);
        break;
    case 2:
        print(&(struct stu s));
    default:
        break;
    }




}
    

