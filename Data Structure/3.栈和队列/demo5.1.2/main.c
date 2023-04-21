#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
#define error -1
#define ok 1

typedef int Status;
typedef int ElemType;

typedef struct sqqueue
{
    ElemType Queue_array[MAX_QUEUE_SIZE];
    int front ;
    int rear;
}SqQueue;

SqQueue Init_CirQueue(void)
{
    SqQueue Q;
    Q.front=Q.rear=0;
    return(Q);
}
Status Insert_CirQueue(SqQueue *Q,ElemType *e)
{
    if ((Q->rear+1)%MAX_QUEUE_SIZE==Q->front)
        return error;
    Q->Queue_array[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAX_QUEUE_SIZE;
    return ok;
}
int ShowStack(SqQueue Q)
{
	while(Q.front!=Q.rear)
	{
		printf("%d\t",Q.Queue_array[Q.front]);
		Q.front=(Q.front+1)%MAX_QUEUE_SIZE;
	}
	printf("\n");
}
Status Delete_CirQueue(SqQueue *Q,ElemType *x)
{
    if(Q->front+1==Q->rear)return error;
    x=Q->Queue_array[Q->front];
    Q->front=(Q->front+1)%MAX_QUEUE_SIZE;
    return ok;
}
int main()
{
    SqQueue Q;
    ElemType x;
    Q=Init_CirQueue();
    Insert_CirQueue(&Q,1);
    Insert_CirQueue(&Q,2);
    Insert_CirQueue(&Q,4);
    Insert_CirQueue(&Q,5);
    Insert_CirQueue(&Q,6);
    ShowStack(Q);
    Delete_CirQueue(&Q,&x);
    printf("%d\t",x);
    Delete_CirQueue(&Q,&x);
    printf("%d\t",x);
    ShowStack(Q);
    Delete_CirQueue(&Q,&x);
    printf("%d\t",x);
    ShowStack(Q);
    printf("Hello world!\n");
    return 0;
}
