#include "SeqList.h"
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 4;
}
void SLCheckCapacity(SL* ps)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		int newCapacity = 0;
		//·ÀÖ¹³õÊ¼»¯
		if (ps->capacity == 0)
		{
			ps->capacity = INIT_CAPACITY;
		}
		else
		{
			ps->capacity = 2 * ps->capacity;
		}
		SLDataType* tmp = (SLDataType *) realloc(ps->a,ps->capacity*sizeof(SLDataType));
		if (tmp = NULL)
		{
			printf("×ª»»Ê§°Ü");
			return;
		 }
		ps ->a =tmp;
	}	
}  

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps != NULL);
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPrint(SL* ps)
{
	assert(ps != NULL);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLPopBack(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size != 0);
	ps->size--;
	 
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps != NULL);
	SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
		
	}
	ps->a[0] = x;
	ps->size++;

}

void SLPopFront(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size != 0);
	for (int i = 0;i<ps->size-1;i++)
	{
		ps->a[i] = ps->a[i+1];
		
		
	}
	ps->size--;

}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps != NULL);
	SLCheckCapacity(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;

}

void SLErase(SL* ps, int pos)
{
	assert(ps != NULL);
	assert(ps->size != 0);
	assert(pos >= 0 && pos <ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];

	}
	ps->size--;


}

int  SLFind(SL* ps, SLDataType x)
{
	assert(ps != NULL);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}

	}
	return -1;
}

void SLDestroy(SL* ps)
{
	assert(ps != NULL);
	if (ps->a != NULL)
	{
		free(ps->a);
		ps->a = NULL;
	}
	ps->size = 0;
	ps->capacity = 0;

}
