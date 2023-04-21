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

ElemType Get_Elem(LNode *head, int i)
{
    int j;
    LNode *p;
    p=head->next;
    j=1;
    while(p!=NULL && j<i)
    {
        p=p->next;
        j++;
    }
    if(j!=i)
    {
        return(-32767);
    }
    else{
        return(p->data);
    }
}
int main()
{
    int data;
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    create_LinkList(head);
    show_LinkList(head);
    printf("Hello world!\n");
    data=Get_Elem(head,3);
    printf("%d",data);
    return 0;
}
