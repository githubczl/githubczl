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

LNode *Merge_LinkList(LNode *La, LNode *Lb)
      /*  �ϲ���La, LbΪͷ����������������   */
{
   LNode *Lc,*pa,*pb,*pc,*ptr;
   Lc=La;
   pc=La;
   pa=La->next;
   pb=Lb->next;
 while(pa!=NULL&& pb!=NULL)
 {
     if(pa->data<pb->data)
    {
        pc->next=pa ;
        pc=pa ;
        pa=pa->next  ;
    }
/*  ��pa��ָ�Ľ��ϲ���paָ����һ�����  */
   if(pa->data>pb->data)
    {
		pc->next=pb;
        pc=pb;
        pb=pb->next  ;
    }
/*  ��pa��ָ�Ľ��ϲ���paָ����һ�����  */
   else if(pa->data==pb->data)
    {
        pc->next=pa;
        pc=pa;
        pa=pa->next;
        ptr=pb;
        pb=pb->next;
        free(ptr);
    }
/*  ��pa��ָ�Ľ��ϲ���pb��ָ���ɾ��  */
}
 if(pa!=NULL)
    {
        pc->next=pa;
    }
else
    {
        pc->next=pb;     /*��ʣ��Ľ������*/
        free(Lb);
    }

return(Lc) ;
}
int main()
{
    LNode *head1,*head2,*head3;
    head1=(LNode *)malloc(sizeof(LNode));
    head1->next=NULL;
    head2=(LNode *)malloc(sizeof(LNode));
    head2->next=NULL;
    create_LinkList(head1);
    show_LinkList(head1);
    printf("\n");
    create_LinkList(head2);
    show_LinkList(head2);

    printf("\n");
    head3 = Merge_LinkList(head1,head2);
    show_LinkList(head3);
    printf("\n");

    printf("Hello world!\n");

    return 0;
}
