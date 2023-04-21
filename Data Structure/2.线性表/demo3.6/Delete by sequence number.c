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

void  Delete_LinkList(LNode *head, int i)
  /*  ɾ����LΪͷ���ĵ������еĵ�i�����  */
{
    int  j=1;
    LNode *p,*q;
    p=head;
    q=head->next;
while( p->next!=NULL&& j<i)
{
    p=q;
    q=q->next;
    j++;
}
if (j!=i)
    printf("i̫���iΪ0!!\n");
else
{
    p->next=q->next;
    free(q);
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



int main()
{
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    create_LinkList(head);
    show_LinkList(head);
    printf("Hello world!\n");
    Delete_LinkList(head,3);
    show_LinkList(head);
    return 0;
}
