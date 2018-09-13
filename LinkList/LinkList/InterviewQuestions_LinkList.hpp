/*
	InterviewQuestions_LinkList.hpp
	2018/9/13 00:34 Created By Rohdea
*/
#include "bitLinkList.hpp"

// 倒叙打印链表 
void ReversePrint(SListNode *pFirst)
{
	//两个指针，tail指向链表已经输出过的节点，
	//cur每次从头开始循环，当cur的下一个节点为tail时，输出cur节点的值，然后将tail置为cur。
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

// 逆置链表 
SListNode * ReverseList(SListNode *pFirst)
{
	//维护三个指针，一个指向已逆置的链表，一个指向未逆置的链表，
	//还有一个指向摘取下来的节点。
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

// 删除非尾无头链表 
void RemoveNodeNotTail(SListNode *pos)
{
	//将pos和pos->pNext的值交换，删除pos->pNext
	if (pos == NULL) return;
	SListNode *del = pos->pNext;
	pos->data = pos->pNext->data;
	pos->pNext = del->pNext;
	free(del);
}

// 无头链表前插入 
void InsertNoHead(SListNode *pos, int data);

/*
约瑟夫环
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

// 冒泡排序 
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


// 合并两个有序链表 
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


// 遍历一次，找到中间结点 
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

// 遍历一次，找到倒数第 k 个结点（k从1开始） 
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

// 遍历一次，删除倒数第 k 个结点（k从1开始），不能用替换删除法 
void RemoveK(SListNode *pFirst, int k)
{
	SListNode *left, *right;
	left = right = pFirst;
	//找到倒数第k+1个
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
	printf("倒序打印：\n");
	ReversePrint(p);
	p = ReverseList(p);
	printf("逆置：\n");
	showList(p);
	printf("删除无头非尾节点：\n");
	RemoveNodeNotTail(p->pNext);
	showList(p);
	//SListDestroy(&p);
	//printf("销毁\n\n");
	//创建环链表
	//CreateCircle(&p, 5);
	//SListNode *tmp = JocephCircle(p, 3);
	//showList(tmp);

	BubbleSort(p);
	showList(p);
	
}