#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
#define error -1
#define ok 1

typedef int Status;
typedef int ElemType;
typedef struct Qnode
{
    ElemType data;
    struct Qnode *next;
}QNode;
typedef struct linkqueue
{
    QNode *front,*rear;
}LinkQueue;
LinkQueue *Init_LinkQueue(void)
{
    LinkQueue *Q;
    QNode *p;
    p=(QNode *)malloc(sizeof(QNode));
    p->next=NULL;
    Q=(LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front=Q->rear=p;
    return(Q);
}
int ShowStack(LinkQueue *Q)
{
    QNode *p;
    p=Q->front->next;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    return ok;
}
Status Insert_CirQueue(LinkQueue *Q,ElemType e)
{
    QNode *p;
    p=(QNode *)malloc(sizeof(QNode));
    if(!p)return error;
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return ok;
}
Status Delete_LinkQueue(LinkQueue *Q,ElemType *x)
{
    QNode *p;
    if (Q->front==Q->rear)return error;
    p=Q->front->next;
    *x=p->data;
    Q->front->next=p->next;
    if(p==Q->rear)
        Q->rear=Q->front;
    free(p);
    return ok;
}
int main()
{
    LinkQueue Q;
    ElemType *x;
    Q=*Init_LinkQueue();
    Insert_CirQueue(&Q,5);
    Insert_CirQueue(&Q,6);
    Insert_CirQueue(&Q,7);
    ShowStack(&Q);
    Delete_LinkQueue(&Q,&x);
    printf("\n%d\t",x);
    Delete_LinkQueue(&Q,&x);
    printf("\n%d\t\n",x);
    printf("Hello world!\n");
    ShowStack(&Q);
    return 0;
}
