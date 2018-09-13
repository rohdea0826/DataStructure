/*
	InterviewQuestions_LinkList.hpp
	2018/9/13 00:34 Created By Rohdea
*/
#include "bitLinkList.hpp"

// �����ӡ���� 
void ReversePrint(SListNode *pFirst)
{
	//����ָ�룬tailָ�������Ѿ�������Ľڵ㣬
	//curÿ�δ�ͷ��ʼѭ������cur����һ���ڵ�Ϊtailʱ�����cur�ڵ��ֵ��Ȼ��tail��Ϊcur��
	if (pFirst == NULL)
	{
		printf("NULL\n");
		return;
	}
	SListNode *cur = pFirst;
	SListNode *tail = NULL;
	printf("NULL");
	while (tail != pFirst)
	{
		cur = pFirst;
		while (cur->pNext != tail)
			cur = cur->pNext;
		printf("<--%d", cur->data);
		tail = cur;
	}
	printf("\n\n");
}

// �������� 
SListNode * ReverseList(SListNode *pFirst)
{
	//ά������ָ�룬һ��ָ�������õ�����һ��ָ��δ���õ�����
	//����һ��ָ��ժȡ�����Ľڵ㡣
	if (pFirst == NULL) return NULL;
	SListNode *Reversed = NULL;
	SListNode *cur = pFirst;
	while (pFirst != NULL)
	{
		cur = pFirst;
		pFirst = pFirst->pNext;
		cur->pNext = Reversed;
		Reversed = cur;
	}
	return Reversed;
}

// ɾ����β��ͷ���� 
void RemoveNodeNotTail(SListNode *pos)
{
	//��pos��pos->pNext��ֵ������ɾ��pos->pNext
	if (pos == NULL) return;
	SListNode *del = pos->pNext;
	pos->data = pos->pNext->data;
	pos->pNext = del->pNext;
	free(del);
}

// ��ͷ����ǰ���� 
void InsertNoHead(SListNode *pos, int data);

/*
Լɪ��
*/
SListNode * JocephCircle(SListNode *pFirst, int k)
{
	SListNode *cur = pFirst;
	SListNode *pre = pFirst;
	int i;

	while (cur->pNext != cur)
	{
		for (i = 1; i < k; i++)
		{
			pre = cur;
			cur = cur->pNext;
		}
		pre->pNext = cur->pNext;
		free(cur);
		cur = pre->pNext;
	}
	cur->pNext = NULL;
	return cur;
}

// ð������ 
void BubbleSort(SListNode *pFirst)
{
	if (pFirst == NULL || pFirst->pNext == NULL) return;
	SListNode *left,*right,*cur;
	int isSorted;
	left = pFirst;
	right = pFirst;
	cur = pFirst;
	while (right->pNext != NULL) 
		right = right->pNext;
	while (left != right)
	{
		cur = left;
		isSorted = 0;
		while (cur != right)
		{
			if (cur->data < left->data)
			{
				DataType tmp = cur->data;
				cur->data = left->data;
				left->data = tmp;
				isSorted = 1;
				break;
			}
			else
				cur = cur->pNext;
		}
		if (isSorted == 1) break;
		left = left->pNext;
	}
}


// �ϲ������������� 
SListNode * MergeOrderedList(SListNode *p1First, SListNode *p2First)
{
	SListNode *newList = NULL;
	SListNode *newNode = NULL;
	SListNode *tail = NULL;
	if (p1First == NULL) return p2First;
	if (p2First == NULL) return p1First;
	if (p1First->data < p2First->data)
	{
		newList = p1First;
		p1First = p1First->pNext;
		tail = newList;
	}
	else
	{
		newList = p2First;
		p2First = p2First->pNext;
		tail = newList;
	}
	while (p1First != NULL && p2First != NULL)
	{
		if (p1First->data < p2First->data || p2First==NULL)
		{
			tail->pNext = p1First;
			p1First = p1First->pNext;
		}
		if(p1First->data >p2First->data ||p1First == NULL)
		{
			tail->pNext = p2First;
			p2First = p2First->pNext;
		}
	}
	tail->pNext = NULL;
	return newList;
}


// ����һ�Σ��ҵ��м��� 
SListNode * FindMid(SListNode *pFirst)
{
	SListNode *mid, *tail;
	mid = tail = pFirst;
	while (tail->pNext != NULL)
	{
		tail = tail->pNext->pNext;
		if (tail == NULL) break;
		mid = mid->pNext;
	}
	return mid;
}

// ����һ�Σ��ҵ������� k ����㣨k��1��ʼ�� 
SListNode * FindK(SListNode *pFirst, int k)
{
	SListNode *left, *right;
	left = right = pFirst;
	while (k-- != 1)
		right = right->pNext;
	while (right->pNext != NULL)
	{
		left = left->pNext;
		right = right->pNext;
	}
}

// ����һ�Σ�ɾ�������� k ����㣨k��1��ʼ�����������滻ɾ���� 
void RemoveK(SListNode *pFirst, int k)
{
	SListNode *left, *right;
	left = right = pFirst;
	//�ҵ�������k+1��
	while (k-- != 0)
		right = right->pNext;
	while (right->pNext != NULL)
	{
		left = left->pNext;
		right = right->pNext;
	}
	SListNode *del = left->pNext;
	left->pNext = del->pNext;
	free(del);
}


void CreateCircle(SListNode **ppFirst, int n)
{
	assert(ppFirst);
	if (*ppFirst != NULL) return;
	*ppFirst = (SListNode *)malloc(sizeof(SListNode));
	SListNode *tail = *ppFirst;
	SListNode *cur = *ppFirst;
	cur->data = 1;
	cur->pNext = NULL;
	int i;
	for (i = 2; i <= n; i++)
	{
		SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
		newNode->data = i;
		newNode->pNext = NULL;
		
		tail->pNext = newNode;
		tail = newNode;
	}
	tail->pNext = *ppFirst;
}

void test()
{
	SListNode *p;
	SListInit(&p);
	SListPushBack(&p, 4);
	SListPushBack(&p, 3);
	SListPushBack(&p, 2);
	SListPushBack(&p, 1);
	showList(p);
	printf("�����ӡ��\n");
	ReversePrint(p);
	p = ReverseList(p);
	printf("���ã�\n");
	showList(p);
	printf("ɾ����ͷ��β�ڵ㣺\n");
	RemoveNodeNotTail(p->pNext);
	showList(p);
	//SListDestroy(&p);
	//printf("����\n\n");
	//����������
	//CreateCircle(&p, 5);
	//SListNode *tmp = JocephCircle(p, 3);
	//showList(tmp);

	BubbleSort(p);
	showList(p);
	
}