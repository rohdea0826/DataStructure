#include "SeqList.h"

void InitSeqList(pSeqList ps)
{
	ps->data = (DataType *)calloc(1,sizeof(DataType));
	ps->sz = 0;
	ps->capacity = 1;
}

void checkCapacity(pSeqList ps)
{
	assert(ps);
	if (ps->sz + 1 > ps->capacity)
	{
		ps->data = (DataType *)realloc(ps->data, ps->capacity*sizeof(DataType) + sizeof(DataType));
		ps->capacity++;
	}
}

void PushBack(pSeqList ps, DataType d)
{
	assert(ps != NULL);
	checkCapacity(ps);
	ps->data[ps->sz++] = d;

}

void PopBack(pSeqList ps)
{
	if (ps->sz == 0) return;
	ps->sz--;
}

void PushFront(pSeqList ps, DataType d)
{
	assert(ps != NULL);
	int i;
	checkCapacity(ps);
	for (i = ps->sz++; i > 0; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[0] = d;
}

void PopFront(pSeqList ps)
{
	assert(ps);
	int i;
	for (i = 0; i < ps->sz; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}


void showSeqList(SeqList p)
{
	int i;
	for (i = 0; i < p.sz; i++)
	{
		printf("%d ", p.data[i]);
	}
	printf("\n");
}
