#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;//0指向左孩子，1指向前驱
	int rtag;//0指向右孩子，1指向后驱
}ThreadNode;
typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

ThreadTree prior;

void creatTree(ThreadTree* T)
{
	ElemType ch;
	ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)
		{
			(*T)->ltag = 0;
		}
		creatTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)
		{
			(*T)->rtag = 0;
		}
	}
}
//中序遍历
void threading(ThreadTree T)
{
	if (T != NULL)  // 只有当 T 不为空时才继续递归
	
		// 递归调用
	
	// 如果 T 为 NULL，函数会直接结束，不再执行任何操作
	{
		threading(T->lchild);
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = prior;
		}
		if (prior->rchild == NULL)
		{
			prior->rtag = 1;
			prior->rchild = T;
		}
		prior = T;
		threading(T->rchild);
	}
}
//1.头结点的Ichild指向二叉树的根  2.头结点的rchild指向遍历的最后一个结点
//3.第一个结点的lchild指向头结点  4.最后一个结点的rchild指向头结点


void inOrderThreading(ThreadTree* head, ThreadTree T)
{
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 0;
	(*head)->rchild = (*head);

	if (T == NULL)
	{
		(*head)->lchild = (*head);

	}
	else
	{
		(*head)->lchild = T;
		prior = (*head);
		threading(T);
		prior->rchild = *head;
		prior->rtag = 1;
		(*head)->rchild = prior; 

	} 
}

void inOrder(ThreadTree T)
{
	ThreadTree curr;
	curr = T->lchild;
	while (curr!=T)
	{
		while (curr->ltag == 0)
		{
			curr = curr->lchild;
		}
		printf("%c", curr->data);
		while (curr->rtag == 1 && curr->rchild != T)
		{                          //最后一个节点
			curr = curr->rchild;
			printf("%c", curr->data);

		}
		curr = curr->rchild;
	}
	printf("\n");
}

int main()
{
	ThreadTree head;
	ThreadTree T;
	creatTree(&T);
	inOrderThreading(&head, T);
	inOrder(head);
	return 0;
}