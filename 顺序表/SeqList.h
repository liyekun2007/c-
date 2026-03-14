#pragma once
#define INIT_CAPACITY 4
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;


}SL;
//初始化结构体
void SLInit(SL* ps);
void SLCheckCapacity(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPrint(SL* ps);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLInsert(SL* ps, int pos,SLDataType x);
void SLErase(SL* ps, int pos);
int  SLFind(SL* ps, SLDataType x);
void SLDestroy(SL* ps);



