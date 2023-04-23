#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 50
typedef char ElemType;

typedef struct BTNode
{
    ElemType data;
    struct BTNode *Lchild,*Rchild;
}BTNode;

BTNode *Creat_Tree()
{
    BTNode *p;
    char c,a;
    scanf("%c%c",&c,&a);//输入a是回车键
    if(c=='$')
    {
        return NULL;
    }
    else
    {
        p = (BTNode *)malloc(sizeof (BTNode));
        p->data=c;
        p->Lchild=Creat_Tree();
        p->Rchild=Creat_Tree();
        return p;
    }
}
void PreGeTree(BTNode *T)
{
    BTNode *Stack[MAX_NODE],*p=T,*q;
    int top=0;
    if(T==NULL)
    {
        printf("the tree is NULL");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%c\t",p->data);
            q=p->Rchild;
            if(q!=NULL)
            {
                Stack[++top]=q;
            }
            p=p->Lchild;
            if(p==NULL&&top!=0)
            {
                p=Stack[top];
                top--;
            }
        }
    }
}
int main()
{
    BTNode *T;
    T = Creat_Tree();
    PreGeTree(T);
    printf("Hello world!\n");
    return 0;
}
