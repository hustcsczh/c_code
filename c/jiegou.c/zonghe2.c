#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct c_node{
    char data;
    struct c_node *next;
} C_NODE;    
//判断回文+链表；

void createLinkList(C_NODE **headp, char s[]) 
{
    
    C_NODE *p, *tail;
    tail = NULL;
    for (int i = 0; i < strlen(s); i++) 
    {
        p = (C_NODE*)malloc(sizeof(C_NODE));
        p->data = s[i];
        p->next = NULL;
        if (tail == NULL)
        {
            *headp = p;
            tail = p;
        }
        else
        {
            tail->next = p; // 相当于*headp->next=p;
            tail = p; //tail与*headp有共同的地址，不方便移动*headp，保持tail始终是*headp->next的地址下一个循环p获得的地址就是*headp->next的地址，
        }
    }
};

void judgePalindrome(C_NODE *head)
{
    C_NODE* p = head;
    char data[50];
    int length = 0;
    while (p != NULL) {
        data[length] = p->data;
        length++;
        p = p->next;
    }
    for (int i = 0; i < length / 2; i++) {
        if (data[i] != data[length - i - 1]) {
            printf("false");
            return ;
        }
    }
    printf("true");
};

int main()  
{
    char s[1000],*pc=s;
    int len=0;
    C_NODE *head,*p;
    scanf("%[^\n]",s);
    createLinkList(&head,s);   
    for(p=head;p;p=p->next) len++;
    if (len!=strlen(s)) 
        { printf("单链表长度不正确");return 1;}
    else for(p=head;p;p=p->next)
    if (p->data!=*pc++)
            { printf("单链表有错误结点");return 1;}
    judgePalindrome(head);
    return 1;
}
