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

void  Delete_Node_value(LNode *head)
/*  删除以L为头结点的单链表中所有值相同的结点  */
{
    LNode *p=head->next, *q, *ptr;
while  ( p!=NULL)   /*  检查链表中所有结点  */
{
    q=p, ptr=p->next;
/*  检查结点p的所有后继结点ptr  */
    while (ptr!=NULL)
     {
         if (ptr->data==p->data)
            {
            q->next=ptr->next;
            free(ptr);
            ptr=q->next;
            }
        else
            {
                q=ptr;
               ptr=ptr->next;
            }
     }
     p=p->next ;
}
}
int main()
{
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    create_LinkList(head);
    show_LinkList(head);
    printf("Hello world!\n");
    Delete_Node_value(head);

    show_LinkList(head);
    return 0;
}
