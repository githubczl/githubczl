#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  3    /*  栈初始向量大小  */
#define STACKINCREMENT 10   /*  存储空间分配增量  */
#define ERROR -1
#define OK  1

typedef int ElemType ;
typedef int Status;

typedef struct sqstack
{
    ElemType  *bottom;     /*  栈不存在时值为NULL  */
    ElemType  *top;      /*  栈顶指针  */
    int   stacksize;      /*  当前已分配空间，以元素为单位  */
}SqStack ;


int Init_Stack(SqStack *S)
{
    S->bottom=(ElemType *)malloc(STACK_SIZE *sizeof(ElemType));
    if (! S->bottom)
        return  -1;
    S->top=S->bottom ;    /*  栈空时栈顶和栈底指针相同  */
    S->stacksize=STACK_SIZE;
    return 1;
}

Status push(SqStack *S , ElemType  e)
{
    if(S->top-S->bottom>=S->stacksize-1)
    {
        S->bottom=(ElemType *)realloc(S->bottom,(STACKINCREMENT+S->stacksize) *sizeof(ElemType));   /*  栈满，追加存储空间  */
        if (! S->bottom)
            return  ERROR;
        S->top=S->bottom+S->stacksize-1;
        S->stacksize+=STACKINCREMENT ;
    }
    *S->top=e;
    S->top++ ; /*  栈顶指针加1，e成为新的栈顶 */
    return OK;
}

int showStack(SqStack *S)
{
    ElemType  *p;
    p=S->bottom;
    while(p<S->top)
    {
        printf("%d\t",*p);
        p++;
    }
}

Status pop( SqStack *S, ElemType  *e)
/*弹出栈顶元素*/
{
    if ( S->top== S->bottom )
    {
        return ERROR ;       /*  栈空，返回失败标志  */
    }
    else
    {
        S->top-- ;//栈顶指针减一
        *e=*S->top ;//e成为新的栈顶
        return  OK ;
    }
}



int main()
{
    SqStack *S;
    ElemType *e;
    S=(SqStack *)malloc(sizeof(SqStack));
    Init_Stack(S);
    push(S,1);
    push(S,2);
    push(S,3);
    push(S,4);
    push(S,5);
    showStack(S);

    printf("\nHello world!\n");
    pop(S,e);
    printf("%d\t",*e);
    pop(S,e);
    printf("%d\t",*e);
    pop(S,e);
    printf("%d\t",*e);
    printf("\nHello world!\n");
    showStack(S);
    return 0;
}
