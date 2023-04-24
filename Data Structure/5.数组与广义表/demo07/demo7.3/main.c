#include <stdio.h>

#define MAX_SIZE 100
#define ElemType int
//自定义 BiTree 类型，表示二叉树
typedef ElemType BiTree[MAX_SIZE];
//存储二叉树
void InitBiTree(BiTree T) {
    ElemType node;
    int i = 0;
    printf("按照层次从左往右输入树中结点的值，0 表示空结点，# 表示输入结束:");
    while (scanf("%d", &node))
    {
        T[i] = node;
        i++;
    }
}


typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int main() {
    int res,n;
    BiTree T = { 0 };
    InitBiTree(T);
    return 0;
}
