#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct stack
{
	ElemType data;
	struct stack * next;   //当下表使用
}Stack;

Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;

}
int isEmpty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("空的\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

void push(Stack* s, ElemType e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;

}
ElemType pop(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("空的\n");
		return 1;
	}
	Stack* p = s->next;
	*e = p->data;
	s->next = p->next;
	free(p);
	return 0;
}
int getTop(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("空的\n");
		return 1;
	}
	*e = s->next->data;

	return 1;
}

int main()
{
	Stack* s = initStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	ElemType e;
	pop(s, &e);
		
	printf("%d\n", e);
	getTop(s, &e);
	printf("%d\n", e);
	return 0;
	return 0;
}