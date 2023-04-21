#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE  100    /*  栈初始向量大小  */
#define ERROR -1
#define OK  1

typedef int ElemType;
typedef int Status;

typedef struct  sqstack
{
    ElemType stack_array[MAX_STACK_SIZE] ;
    int  top;
}SqStack ;

SqStack Init_Stack(void)
{
    SqStack  S;
    S.top=0 ;
    return (S) ;
}

Status push(SqStack *S, ElemType  e)
   /*  使数据元素e进栈成为新的栈顶  */
{
    if  (S->top==MAX_STACK_SIZE)
        return  ERROR;      /*  栈满，返回错误标志    */

    S->stack_array[S->top]=e;   /* e成为新的栈顶  */
    S->top++;      /*  栈顶指针加1  */
    return OK;        /*  压栈成功    */
}


Status pop(SqStack *S, ElemType *e)
      /*弹出栈顶元素*/
{
    if ( S->top==0 )
        return ERROR ;       /*  栈空，返回错误标志    */
    S->top-- ;
    *e=S->stack_array[S->top];
    return OK ;
}


int ShowStack(SqStack S)
{
    while(S.top>0)
    {
        S.top--;
        printf("%d\t",S.stack_array[S.top]);
    }
}


int main()
{
    SqStack  S;
    ElemType e;
    S=Init_Stack();
    printf("Hello world!\n");
    push(&S,1);
    push(&S,2);
    push(&S,3);
    push(&S,4);
    push(&S,5);
    ShowStack(S);
    printf("\nHello world!\n");
    pop(&S,&e);
    printf("%d\t",e);
    pop(&S,&e);
    printf("%d\t",e);
    pop(&S,&e);
    printf("%d\t",e);
    printf("\nHello world!\n");
    ShowStack(S);
    return 0;
}
