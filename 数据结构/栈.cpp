#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;   //当下表使用
}Stack;
//初始化
void initStack(Stack* s)
{
	s->top = -1;
}

//typedef struct
//{
//	ElemType* data;
//	int top;   //当下表使用
//}Stack;
//Stack* initStack2()//动态初始化
//{
//	Stack* s = (Stack*)malloc(sizeof(Stack));
//	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); data[1]=*(data+1)
//	s->top = -1;
//	return s;
//}
//int main()
//{
//	Stack* s =initStack2();
//	
//	push(s, 10);
//	push(s, 20);
//	push(s, 30);
//	ElemType e;
//	pop(s, &e);
//	printf("%d\n", e);
//	getTop(s, &e);
//	printf("%d\n", e);
//	return 0;
//}

int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 1;
	}
	else
	{
		return 0; 
	}

}

int push(Stack* s, ElemType e)
{
	if (s->top >= MAXSIZE - 1)
	{
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

ElemType pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 1;
	}
	*e = s->data[s->top];
	s->top--;
	return 0;
}

int getTop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 1;
	}
	*e = s->data[s->top];
	
	return 1;
}

int main()
{
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	ElemType e;
	pop(&s, &e);
	printf("%d\n", e);
	getTop(&s, &e);
	printf("%d\n", e);
	return 0;
}
