#include <stdio.h>

#define MAX_SIZE 100
#define ElemType int
//�Զ��� BiTree ���ͣ���ʾ������
typedef ElemType BiTree[MAX_SIZE];
//�洢������
void InitBiTree(BiTree T) {
    ElemType node;
    int i = 0;
    printf("���ղ�δ��������������н���ֵ��0 ��ʾ�ս�㣬# ��ʾ�������:");
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
