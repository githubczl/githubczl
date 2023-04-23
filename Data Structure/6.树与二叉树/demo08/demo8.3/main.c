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
void PreGetTree( BTNode *T)
{
    if(T!=NULL)
    {
        PreGetTree(T->Lchild);
        printf("%c\t",T->data);
        PreGetTree(T->Rchild);
    }
}
int main()
{
    BTNode *T;
    T = Creat_Tree();
    PreGetTree(T);
    printf("\nHello world!\n");
    return 0;
}
