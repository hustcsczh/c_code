#include <stdio.h>
#include <stdlib.h>

// 定义链表结点
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

// 创建链表
Node *createLinkedList(char *str)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *p = head;
    for (int i = 0; str[i] != '\0'; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = str[i];
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
    }
    return head;
}

// 遍历链表并输出字符
void traverseLinkedList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}


// 删除链表中的某个字符结点
void deleteNode(Node *head, char target)
{
    Node *p = head;
    while (p->next != NULL)
    {
        if (p->next->data == target)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            free(temp);
            break;
        }
        p = p->next;
    }
}

// 在链表中插入包含某个字符的结点
/*void insertNode(Node *head, char target)
{
    Node *p = head;
    int minDiff = 26; // 初始化为最大值
    Node *insertPos = NULL;
    while (p->next != NULL)
    {
        int diff = abs(p->next->data - target);
        if (diff < minDiff)
        {
            minDiff = diff;
            insertPos = p;
        }
        p = p->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = target;
    newNode->next = insertPos->next;
    insertPos->next = newNode;
}*/

int main()
{
    char str[100];
    scanf("%s", str);
    Node *head = createLinkedList(str);
    traverseLinkedList(head);
    return 0;
}
