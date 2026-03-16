#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;

}TreeNode;
typedef TreeNode* BiTree;

int index = 0;
char str[] = "ABC#DE";
void creatTree(BiTree* T)
{
	ElemType ch;
	
	ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}
//前序遍历
void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}
//中序遍历
void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	inOrder(T->lchild);
	printf("%c", T->data);
	inOrder(T->rchild);
}
//后序遍历
void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	postOrder(T->lchild); 
	postOrder(T->rchild);
	printf("%c", T->data);
}

//非递归版本前序
//while (T != NULL) {
//	printf("%c ", T->data);  // 访问根
//	push(s, T);              // 手动保存当前节点
//	T = T->lchild;           // 遍历左子树
//}
//// 左子树遍历完毕
//while (!isEmpty(s)) {
//	pop(s, &T);              // 取出保存的节点
//	T = T->rchild;           // 遍历右子树
//	// 对右子树重复上述过程
//}