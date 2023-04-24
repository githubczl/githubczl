#include <stdio.h>
#include <stdlib.h>

typedef char Type;
typedef struct Tree
{
    struct Tree *left;
    struct Tree *right;
    Type data;
}Node;
Node *CreatTreeNode(Type x)
{
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=x;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void PreOrder(Node* root)
{
    if(root==0)
    {
        printf("NULL");
        return ;
    }
    printf("%c",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
int main()
{
    Node* a=CreatTreeNode('a');
    Node* b=CreatTreeNode('b');
    Node* c=CreatTreeNode('c');
    Node* d=CreatTreeNode('d');
    Node* e=CreatTreeNode('e');
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    PreOrder(a);
    system("pause");

    printf("Hello world!\n");
    return 0;
}
