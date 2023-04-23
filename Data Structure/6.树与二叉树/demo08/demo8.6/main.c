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
    scanf("%c%c",&c,&a);//����a�ǻس���
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
   int top=0,tag[50];
   BTNode *Stack[MAX_NODE],*p=T,*q;
   if(T==NULL)
   {
       printf("the tree is NULL!");
   }
   else
   {
       while(p!=NULL || top!=0)
       {
           if(p!=NULL)
           {
               tag[top+1] = 0;
               Stack[++top]=p;
               p=p->Lchild;
           }
           else
           {
               q=Stack[top];
               top--;
               if(tag[top+1]==0)
               {
                   Stack[++top]=q;
                   tag[top]=1;
                   p=q->Rchild;
               }
               else
               {
                   printf("%c\t",q->data);
                   p=NULL;
               }
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
