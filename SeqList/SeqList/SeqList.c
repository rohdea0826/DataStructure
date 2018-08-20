#include "SeqList.h"

//动态创建堆上的空间，
//一般不会初始化容量为1，这里只是为了方便测试
void InitSeqList(pSeqList ps)
{
	ps->data = (DataType *)calloc(1,sizeof(DataType));
	ps->sz = 0;
	ps->capacity = 1;
}

//检测容量，若不足则容量加倍
void checkCapacity(pSeqList ps)
{
	assert(ps);
	if (ps->sz + 1 > ps->capacity)
	{
		ps->data = (DataType *)realloc(ps->data, ps->capacity*sizeof(DataType) 
			+ sizeof(DataType)*ps->capacity);
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
	if (ps->sz == 0) return;
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
	if (ps->sz == 0) return;
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

static void swap(DataType *left, DataType *right)
{
	DataType tmp = *left;
	*left = *right;
	*right = tmp;
}

void SelectSort(pSeqList ps)
{
	assert(ps);
	if (ps->sz == 0) return;
	int left = 0, right = 0;
	int i = 0;
	int j = 0;
	DataType min = ps->data[0];
	DataType max = ps->data[0];
	for (i = 0; i < ps->sz / 2; i++)
	{
		min = ps->data[i];
		max = ps->data[i];
		for (j = i; j < ps->sz - i; j++)
		{
			if (ps->data[j] <= min)
			{
				left = j;
				min = ps->data[left];
			}
			if (ps->data[j] >= max)
			{
				right = j;
				max = ps->data[right];
			}
		}
		swap(ps->data + i, ps->data + left);
		if (right == i) right = left;
		swap(ps->data + ps->sz - i - 1, ps->data + right);
	}
}

int BinarySearch(pSeqList ps, DataType d)
{
	int left = 0;
	int right = ps->sz - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (d < ps->data[mid])
		{
			right = mid - 1;
		}
		else if (d > ps->data[mid])
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
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
