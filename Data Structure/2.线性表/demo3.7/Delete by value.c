#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR -1
typedef int ElemType;

typedef struct Londe
{
    ElemType data;
    struct Londe *next;
}LNode;


void show_LinkList(LNode *head)
{
    LNode *p;
    p=head->next;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

int create_LinkList(LNode *head)
{
    int d;
    LNode *p,*q;
    p=head;
    while(1)
    {
        scanf("%d",&d);//在这里我本是写着scanf("%d\t",&d);最后运行不出结果
        if(d==32767)
        {
            break;
        }
        q=(LNode *)malloc(sizeof(LNode));
        q->data=d;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    return 1;
}

void  Delete_LinkListByValue(LNode *head,int key)
/*  删除以L为头结点的单链表中值为key的第一个结点  */
{
    LNode *p=head,  *q=head->next;
    while  ( q!=NULL&& q->data!=key)
    {
        p=q;
        q=q->next;
    }
    if(q==NULL)
    {
        printf("所要删除的结点不存在!!\n");
        return ;
    }
    if  (q->data==key)
    {
        p->next=q->next;
        free(q);
    }
    else
        printf("所要删除的结点不存在!!\n");
}
int main()
{
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    create_LinkList(head);
    show_LinkList(head);
    printf("Hello world!\n");
    Delete_LinkListByValue(head,4);
    show_LinkList(head);
    return 0;
}
