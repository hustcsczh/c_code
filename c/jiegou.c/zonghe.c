#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"intNode.h"

struct intNode *createList();
void printList(struct intNode *head);
void printList2(struct intNode *head);
void deleteNodes(struct intNode **hp, char c);
void insertNode(struct intNode **hp, char c);

int main()//输入字符串，在输入字符，有则删去，无则插入            //debug 只删除第一个char
{
    struct intNode *head;
    head = createList();
    printList2(head);
    printList(head);
    char c;
    scanf("%c", &c);
    struct intNode *p;
    p = head;
    for (; p != NULL; p = p->next)
    {
        if (p->date == c)
        {
            deleteNodes(&head, c);
            printList(head);
            return 0;
        }
    }
    insertNode(&head, c);
    printList(head);
    return 0;
}

struct intNode *createList()
{
    struct intNode *head, *p, *tail;
    char c;
    p = (struct intNode *)malloc(sizeof(struct intNode));
    head =tail = p;
    if ((c = getchar()) == '\n')
    {
        free(head);
        free(tail);
        free(p);
        return head;
    }
    while (c != '\n')
    {
        p = (struct intNode *)malloc(sizeof(struct intNode));
        p->date = c;
        p->next = NULL;
        tail->next = p;
        tail = p; // 这里为什么不能调换位置？；
        //tail->next = p;
        if ((c = getchar()) == '\n')
        {
            return head;
        }
    }
    return head;
}

void printList(struct intNode *head)
{
    struct intNode *p;
    p = head;
    while (p != NULL)
    {
        printf("%c", p->date);
        p = p->next;
    }
    printf("\n");
}
void printList2(struct intNode *head)
{
    struct intNode *p;
    p = head;
    while (p != NULL)
    {
        printf("%c ", p->date);
        p = p->next;
    }
    printf("\n");
}

void deleteNodes(struct intNode **hp, char c)
{
    struct intNode *p, *last, *temp;
    p = *hp;
    while (p != NULL)
    {
        if (p->date == c)
        {
            if (p == *hp)
            {
                *hp = p->next;
                free(p);
                p = *hp;
            }
            else
            {
                last->next = p->next;
                temp = p;
                p = p->next;
                free(temp);
            }
        }
        else
        {
            last = p;
            p = p->next;
        }
    }
}

void insertNode(struct intNode **hp, char c) // 插入节点
{
    struct intNode *p, *last, *new, *p1;

    new = (struct intNode *)malloc(sizeof(struct intNode)); 
    new->date = c;
    p1 = p = *hp;
    int min = 100, target = 0;
    for (int i = 0; p != NULL; p = p->next, i++)
    {
        int x;
        x = (int)p->date - (int)c;
        if (min > fabs(x))
        {
            min = fabs(x);
            target = i;//标记相差最小的位置
        }
    }
    while (target-- >= 0)//移动到相应位置  last指向前一个位点；p指向后一个位点
    {
        last = p1;
        p1 = p1->next;
    }
    if (p1 == NULL)
    {                     /* 插入点是链尾 */
        new->next = NULL; /*新节点为 链尾*/
        last->next = new;
    }
    else if (p1 == *hp)
    {
        new->next = *hp;
        *hp = new;
    }
    else
    {
       // new->next = p1;                        
        last->next = new;   //这里顺序无所谓
        new->next = p1;
    }
}
