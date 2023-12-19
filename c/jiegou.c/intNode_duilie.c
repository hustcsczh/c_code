#include <stdio.h>
#include <stdlib.h>
#include "intnode.h"
/// ////////////////////////////////////////顺序输出链表---也就是队列
struct intNode *createList(void);                                       //创建节点
void printList(struct intNode *head);                                   //打印
int countNodes(struct intNode *head);                                   //统计个数
struct intNode* findNodes(struct intNode *head, int n);                //查找节点
int deleteNodes(struct intNode **hp, int n);                           /* 删除值为n的结点，成功删除返回1；否则，返回0。*/
struct intNode *insertNode(struct intNode **hp, int x);                // 插入节点，返回值为地址

int main()
{
    struct intNode *head;
    head = createList();
    printList(head);
    countNodes(head);
    int n;
    scanf("%d", &n);
    findNodes(head, n); // 查找n;
    deleteNodes(&head, 4/*可替换*/); // 删除n;
    printList( insertNode(&head, 5/*可替换*/) );  // 插入n;
    return 0;
}

struct intNode *createList()
{
    struct intNode *head, *p, *tail;
    int x;
    head = NULL;
    tail = NULL;
    scanf("%d", &x); // 输入0结束；
    while (x)
    {
        p = (struct intNode *)malloc(sizeof(struct intNode));
        p->date = x;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p; // 这里为什么不能调换位置？；
            // tail->next = p;
        }
        scanf("%d", &x);
    }
    return head;
}

void printList(struct intNode * head)
{
    struct intNode *p;
    p = head;
    while (p != NULL)
    {
        printf("%d", p->date);
        p = p->next;
    }
    printf("\n");
}

int countNodes(struct intNode * head) // 统计节点个数
{
    struct intNode *p = head;
    int num = 0;
    while (p != NULL)
    {
        num++;
        p = p->next;
    }
    return num;
}

struct intNode *findNodes(struct intNode * head, int n) // 查找节点
{
    struct intNode *p = head;
    if (p) /* 链表非空，查找 */
    {
        if (p->date == n)
            return p; /* 找到，返回该结点的地址 */
        else
            return (findNodes(p->next, n)); //* 递归查找 *也可以循环；
    }
    else
        return NULL;
}

int deleteNodes(struct intNode* *hp, int n) /* 删除值为n的结点，成功删除返回1；否则，返回0。*/
{
    struct intNode *p,
    *last;
    p = *hp;
    while (p != NULL && p->date != n)
    {                /* 查找成员值与n相等的结点 */
        last = p;    /* last指向当前结点 */
        p = p->next; /* p指向下一结点 */
    }
    if (p == NULL)
        return 0; /* 没有符合条件的结点 */
    if (p == *hp) /* 被删结点是链头*/
        *hp = p->next;
    else /* 被删结点不是链头 */
        last->next = p->next;
    free(p); /* 释放被删结点的存储 */
    return 1;
}

struct intNode *insertNode(struct intNode **hp, int x)//插入节点
{
    struct intNode *p,*last,*new;
    new = (struct intNode *)malloc(sizeof(struct intNode)); /* 创建一个新节点 */
    new->date = x;
    p = *hp;
        /* 寻找插入位置 */
    while (p != NULL &&x!=p->date)
    {
        last = p;
        p = p->next;
    }
    //查找到之后；
    if (p == *hp)
    {              /* 插入点是链头 */
        *hp = new; /* 新节点为 链头*/
        new->next = p;
    }
    else if (p == NULL)
    {                     /* 插入点是链尾 */
        new->next = NULL; /*新节点为 链尾*/
        last->next = new;
    }
    else
    {                  /* 插入点是链中 */
        new->next = p; /*新节点为 p的前驱结点*/
        last->next = new;
    }
    return new;//返回值为结构体指针
}
