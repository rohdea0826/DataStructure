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

void showSeqList(SeqList p)
{
	int i;
	for (i = 0; i < p.sz; i++)
	{
		printf("%d ", p.data[i]);
	}
	printf("\n");
}
