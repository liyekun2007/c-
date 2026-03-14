#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *prev, * next;
}Node;

Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

void insertHead(Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	p->prev = L;
	if (L->next != NULL)
	{
		L->next->prev = p;
	}
	
	L->next = p;
}

void printflist(Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void inserttail(Node* L,ElemType e)
{
	
	Node* tail = L->next;
	while (tail->next != NULL)
	{
		tail = tail ->next;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->prev = tail;	
	p->next = NULL;
}

void insertpos(Node* L, int pos, ElemType e)
{
	Node* p = L->next;
	for (int i = 1; i < pos - 1; i++)//i<pos-1  走到第pos-1个节点
	{                                 //i为几，当前就走到了第i个节点
		p = p->next;
	}
	Node* buy = (Node*)malloc(sizeof(Node));
	buy->data = e;
	buy->next = p->next;
	buy->prev = p;
	p->next->prev = buy;
	p->next = buy;
}
void deletepos(Node* L, int pos)
{
	Node* p = L->next;
	for (int i = 1; i < pos - 1; i++)//i<pos-1  走到第pos-1个节点
	{                                 //i为几，当前就走到了第i个节点
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;
	q->next->prev = p;
	free(q);

}


int main()
{
	Node* list = initList();
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	inserttail(list, 40);
	inserttail(list, 50);
	insertpos(list, 4, 14);
	printflist(list);

	return 0;
}