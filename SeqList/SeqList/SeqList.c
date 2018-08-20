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

void InsertList(pSeqList ps, int pos, DataType d)
{
	assert(ps);
	DataType tmp = ps->data[ps->sz - 1];
	int i = ps->sz - 1;
	while (i != pos )
	{
		ps->data[i] = ps->data[i - 1];
		--i;
	}
	ps->data[pos] = d;
	PushBack(ps, tmp);
}

void Remove(pSeqList ps, DataType d)
{
	assert(ps != NULL);
	if (ps->sz = 1)
	{
		if (ps->data[0] == d)
			PopBack(ps);
		return;
	}
	int i = 0;
	while (ps->data[i] != d)
	{
		++i;
	}
	while (i != ps->sz - 1)
	{
		ps->data[i] = ps->data[i + 1];
		++i;
	}
	ps->sz--;
}

void RemoveAll(pSeqList ps, DataType d)
{
	assert(ps);
	int i = 0;
	int j = ps->sz - 1;
	int k = 0;
	while (i != ps->sz)
	{
		while (ps->data[j] != d)
		{
			--j;
		}
		if (j < 0) return;
		k = j;
		while (k != ps->sz)
		{
			ps->data[k] = ps->data[k + 1];
			++k;
		}
		--ps->sz;
	}
}

int FindList(pSeqList ps, DataType d)
{
	assert(ps);
	int i = 0;
	while (i != ps->sz)
	{
		if (ps->data[i] == d) return i;
		++i;
	}
	return -1;
}

void BubbleSort(pSeqList ps)
{
	assert(ps);
	int i = 0;
	int j = 0;
	DataType tmp;
	for (i = 0; i < ps->sz - 1; i++)
	{
		int isSorted = 1;
		for (j = 0; j < ps->sz - i - 1; j++)
		{
			if (ps->data[j] > ps->data[j + 1])
			{
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
				isSorted = 0;
			}
		}
		if (isSorted = 1) return;
	}
}


void showSeqList(SeqList p)
{
	if (p.sz == 0) return;
	int i;
	for (i = 0; i < p.sz; i++)
	{
		printf("%d ", p.data[i]);
	}
	printf("\n");
}

void DestroySeqList(pSeqList p)
{
	free(p->data);
	p->sz = 0;
	p->capacity = 0;
}
