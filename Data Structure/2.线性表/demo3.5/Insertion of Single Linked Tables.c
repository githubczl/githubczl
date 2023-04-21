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

LNode Insert_LNode(LNode *head,int i,ElemType e)
{
    int j=1;
    LNode *p,*q;
    p=head->next;
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1)
    {
        printf("i太大或i=0！！\n");
    }
    else{
        q=(LNode *)malloc(sizeof(LNode));
        q->data=e;
        q->next=p->next;
        p->next=q;
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
    Insert_LNode(head,3,22);
    show_LinkList(head);

    return 0;
}
