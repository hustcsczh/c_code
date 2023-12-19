#include <stdio.h>
#include <stdlib.h>
#include "intnode.h"
/// ////////////////////////////////////////逆序输出链表---也就是栈
                                        //只使用一个指针head，1->2->3  存入栈只能从3->2->1依次取出
struct intNode *createList(void);
void printList(struct intNode *head);

int main()
{
    struct intNode *head;
    head = createList();

    printList(head);
    return 0;
}

struct intNode *createList()
{
    struct intNode *head, *p;
    int x;
    head = NULL;
    scanf("%d", &x);
    while (x)
    {
        p = (struct intNode *)malloc(sizeof(struct intNode));
        p->date = x;
        p->next = head; // 每次创建新的地址，都使得下一个next为NULL；防止最后一次产生野指针；头插法
        head = p;
        scanf("%d", &x);
    }
    return head; // 这个head的地址是最后一个元素，为什么print函数里面能够p->next?//知道了，
}

void printList(struct intNode *head)
{
    struct intNode *p;
    p = head;
    while (p != NULL)
    {
        printf("%d", p->date);
        p = p->next;
    }
}
