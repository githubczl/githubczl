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

LNode *Locate_Node(LNode *head,int key)
{
    LNode *p=head->next;
    while(p!=NULL&&p->data!=key)
    {
        p=p->next;
    }
    if(p->data==key)
    {
        return p;
    }
    else{
        printf("索要查找的节点不存在！！！");
        return(NULL);
    }
}
int main()
{
    LNode *head,*p;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    create_LinkList(head);
    show_LinkList(head);
    printf("Hello world!\n");
    p=Locate_Node(head,4);
    printf("data=%d\n",p->data);
    return 0;
}

