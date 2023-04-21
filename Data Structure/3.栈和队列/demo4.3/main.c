#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE  100    /*  栈初始向量大小  */
#define ERROR -1
#define OK  1

typedef int ElemType ;
typedef int Status;

typedef  struct  Stack_Node
{
    ElemType   data ;
    struct Stack_Node  *next ;
}Stack_Node ;

Stack_Node *Init_Link_Stack(void)
{
    Stack_Node  *top ;
    top=(Stack_Node  *)malloc(sizeof(Stack_Node )) ;
    top->next=NULL ;
    return(top) ;
}


Status push(Stack_Node *top , ElemType e)
{
    Stack_Node  *p ;
    p=(Stack_Node  *)malloc(sizeof(Stack_Node)) ;
    if (!p)
        return  ERROR;
/*  申请新结点失败，返回错误标志 */
    p->data=e ;
    p->next=top->next  ;
    top->next=p ;    /*  钩链  */
    return OK;
}

void showStack(Stack_Node *top)
{
    Stack_Node *p;
    p=top->next;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}


Status pop(Stack_Node  *top , ElemType *e)
/*  将栈顶元素出栈  */
{
    Stack_Node  *p ;
    if  (top->next==NULL )
        return ERROR ;    /*  栈空，返回错误标志    */
    p=top->next ;
    *e=p->data ;    /*  取栈顶元素  */
    top->next=p->next ;     /*  修改栈顶指针  */
    free(p) ;
    return OK ;
}

void conversion(int n , int d)
/*将十进制整数N转换为d(2或8)进制数*/
{
    Stack_Node *top ;
    int k, e;
    top=Init_Link_Stack();
    while(n>0)
    {
        k=n%d;
        push(top,k) ;
        n=n/d ;
    }
          /*  求出所有的余数，进栈  */
    while(top->next!=NULL)     /*  栈不空时出栈，输出  */
    {
        pop(top,&e) ;
        printf("%1d",e) ;
    }
}


int main()
{
    //conversion(1024,8);
    Stack_Node *top ;
    ElemType e;
    top=Init_Link_Stack();
    push(top,1);
    push(top,2);
    push(top,3);
    push(top,4);
    push(top,5);
    showStack(top);
    printf("\nHello world!\n");
    pop(top,&e);
    printf("%d\t",e);
    pop(top,&e);
    printf("%d\t",e);
    pop(top,&e);
    printf("%d\t",e);
    printf("\nHello world!\n");
    showStack(top);
    printf("\nHello world!\n");
    return 0;
}
