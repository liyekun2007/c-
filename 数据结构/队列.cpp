#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear= 0;
}

int isEmpty(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueFull(Queue* Q)
{
	if (Q->front > 0)
	{
		int step = Q->front;
		for (int i = Q->front; i < Q->rear; i++)
		{
			Q->data[i - step] = Q->data[i];
			
		}
		Q->front = 0;
		Q->rear = Q->rear - step;
		return 1;
	}
	else
	{
		printf("真的满了\n");
		return 0;
	}

}

int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}
//出队
ElemType dequeue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	ElemType e = Q->data[Q->front];
	Q->front++;
	return e;
}
//入队
int equeue(Queue* Q, ElemType e)
{
	if (Q->rear >= MAXSIZE)
	{
		if (!queueFull(Q))
		{
			printf("满了\n");
			return 0;
		}
	}
	
	Q->data[Q->rear] = e;
	Q->rear++;
	return 1;
}

int main()
{
	Queue q;
	initQueue(&q);
	equeue(&q, 10);
	equeue(&q, 20);
	equeue(&q, 30);
	equeue(&q, 40);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	return 0;
}


//动态分配内存
//#define MAXSIZE 100
//
//typedef int ElemType;
//typedef struct
//{
//	ElemType* data;
//	int front;
//	int rear;
//}Queue;
//
//Queue* initQueue()
//{
//	Queue* q = (Queue*)malloc(sizeof(Queue));
//	q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//	q->front = 0;
//	q->rear = 0;
//	return q;
//}