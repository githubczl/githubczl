#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef char Tree[MAX_SIZE];
void InitTree(Tree tree)
{
    int i;
    for ( i=0;i<MAX_SIZE;i++)
    {
        tree[i]='\0';
    }
}
void CreatTree(Tree tree,int i)
{
    char ch;
    ch=getchar();
    fflush(stdin);
    if(ch=='$')
    {
        tree[i]='\0';
        return;
    }
    tree[i]=ch;
    printf("输入左子树：\n");
    CreatTree(tree,2*i+1);
    printf("输入右子树：\n");
    CreatTree(tree,2*(i+1));
}
void PrintTree(Tree tree)
{
    int i;
    for(i=0;i<MAX_SIZE;i++)
    {
        printf("%c",tree[i]);
    }
}
void main()
{
    Tree tree;
    InitTree(tree);
    printf("输入根节点内容：\n");
    CreatTree(tree,0);
    PrintTree(tree);
    printf("Hello world!\n");
    return 0;
}
