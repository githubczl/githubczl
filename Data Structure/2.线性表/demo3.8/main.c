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
        scanf("%d",&d);//�������ұ���д��scanf("%d\t",&d);������в������
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
/*  ɾ����LΪͷ���ĵ�����������ֵ��ͬ�Ľ��  */
{
    LNode *p=head->next, *q, *ptr;
while  ( p!=NULL)   /*  ������������н��  */
{
    q=p, ptr=p->next;
/*  �����p�����к�̽��ptr  */
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
