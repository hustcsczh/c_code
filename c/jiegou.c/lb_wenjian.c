#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
    char s[20];
    char n[10];
    int c[4];
    struct stu *next;
} STU;

STU*  createlist(STU **head);
void print(STU **head);
void sort(STU **head);
void change(STU **head);
void avarge(STU **head,int n);
void put(STU **head);
void out(STU **head);

int main() {
    int a;
    int n = 0;
    scanf("%d", &a);
    STU *head = NULL;
    STU *p1 = NULL, *p2 = NULL, *p3 = NULL;
    while (a != 0) {
        switch (a) {
            case 0:
                break;
            case 1:
                if(p1!=NULL)
                {
                    createlist(&p1);
                    break;
            
                }
                p1=createlist(&head);
                break;
            case 2:
                print(&head);
                break;
            case 3:
                change(&head);
                break;
            case 4:
                avarge(&head,n);
                break;
            case 5:
                n = 1;
                avarge(&head,n);
                break;
            case 6:
                put(&head);
                break;
            case 7:
                out(&head);
                break;
            default:
                break;
        }
        scanf("%d", &a);
    }

    return 0;
}

STU*  createlist(STU **head) {
    STU *p, *tail = *head;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        p = (STU *)malloc(sizeof(STU));
        scanf("%s %s", p->s,p->n);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &(p->c[j]));
        }
        p->next = NULL;
        if (*head == NULL) {
            *head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    return tail;
}

void print(STU **head) {
    STU *p = *head;
    while (p!= NULL) {
        printf("%s %s %d %d %d %d\n", p->s, p->n,p->c[0],p->c[1], p->c[2], p->c[3]);
        p= p->next;
    }
}

void change(STU **head)
{
    STU *p = *head;
    char str[20];
    int g, sc;
    scanf("%s %d %d",str, &g,&sc);
    for (; p!= NULL;p=p->next)
    {
        if(strcmp(str,p->s)==0)
        {
            p->c[g - 1] = sc;
            return;
        }
    }
}

void avarge(STU **head,int n)
{
    STU *p = *head;
    while (p!= NULL)
    {
        float a[4];
        int b;
        float c;
        b= p->c[0] + p->c[1] + p->c[2] + p->c[3];
        c = (p->c[0] + p->c[1] + p->c[2] + p->c[3]) / 4.0;
        printf("%s %s", p->s, p->n);
        if(n)
        {
            printf(" %d", b);
        }
        printf(" %.2f\n", c);
        p = p->next;
    }
}

void put(STU **head)
{
    STU *p = *head;
    FILE *put;
    if((put=fopen("stu.dat","wb"))==NULL)
    {
        exit(-1);
    }
    for (; p != NULL;p=p->next)
    {
        fwrite(&p, sizeof(STU), 1, put);//整个结构体一起读入/输出
    }
    fclose(put);
}

void out(STU **head)
{
    STU *p = *head;
    FILE *out;
    if((out=fopen("stu.dat","wb"))==NULL)
    {
        exit(-1);
    }
    for(; p != NULL;p=p->next)
    {
        fread(&p, sizeof(STU), 1, out);
    }
    fclose(out);
}