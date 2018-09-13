#pragma once
/*	
	bitLinkList.hpp
	2018/9/12 23:31	Created By Rohdea
	测试程序为testbitLList()
	ps：题目结构体定义pNext应该为SListNode而不是ListNode，查找函数应返回SListNode而不是int
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



//代码实现链表的操作函数

// 值类型 
typedef int DataType;

typedef struct SListNode {
	DataType data; // 值 
	struct SListNode *pNext; // 指向下一个结点   //好坑啊，题目里少了个S
} SListNode;

// 初始化 
void SListInit(SListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

// 尾部插入 
void SListPushBack(SListNode** ppFirst, DataType data)
{
	//*ppFirst为空直接插入，否则遍历至最后一个非空节点插入。
	assert(ppFirst);
	SListNode *cur = *ppFirst;
	SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
	newNode->data = data;
	newNode->pNext = NULL;
	if (*ppFirst == NULL)
		*ppFirst = newNode;
	else
	{
		while (cur->pNext != NULL)
			cur = cur->pNext;
		cur->pNext = newNode;
	}
}

// 头部插入 
void SListPushFront(SListNode **ppFirst, DataType data)
{
	//若为空，直接插入；否则将新节点指向*ppFirst，*ppFirst指向新节点。
	assert(ppFirst != NULL);
	SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
	newNode->data = data;
	newNode->pNext = NULL;
	if (*ppFirst == NULL)
		*ppFirst = newNode;
	else
	{
		newNode->pNext = *ppFirst;
		*ppFirst = newNode;
	}
}

// 尾部删除 
void SListPopBack(SListNode **ppFirst)
{
	//若*ppFirst为空，直接返回；若只有一个节点，释放置空；否则删除尾节点。
	assert(ppFirst != NULL);
	SListNode *cur = *ppFirst;
	if (*ppFirst == NULL)
		return;
	else if ((*ppFirst)->pNext == NULL)
	{
		free(cur);
		*ppFirst = NULL;
	}
	else
	{
		while (cur->pNext->pNext != NULL)
			cur = cur->pNext;
		free(cur->pNext);
		cur->pNext = NULL;
	}
}

// 头部删除 
void SListPopFront(SListNode **ppFirst)
{
	//若为空，直接返回；否则删除头结点
	assert(ppFirst);
	if (*ppFirst == NULL)
		return;
	else
	{
		SListNode *del = *ppFirst;
		*ppFirst = (*ppFirst)->pNext;
		free(del);
	}
}

// 给定结点插入，插入到结点前 
void SListInsert(SListNode **ppFirst, SListNode *pPos, DataType data)
{
	//假定给定节点一定存在于链表中。若首节点为给定节点，头插；否则找到节点并插入。
	assert(ppFirst != NULL);
	SListNode *newNode = (SListNode*)malloc(sizeof(SListNode));
	SListNode *cur = *ppFirst;
	newNode->data = data;
	newNode->pNext = NULL;
	if (*ppFirst == pPos) SListPushFront(ppFirst, data);
	else
	{
		while (cur != NULL && cur->pNext != pPos)
			cur = cur->pNext;
		if (cur != NULL)
		{
			newNode->pNext = cur->pNext;
			cur->pNext = newNode;
		}
	}
}

// 给定结点删除 
void SListErase(SListNode **ppFirst, SListNode *pPos)
{
	//假定给定节点存在于链表中。若链表为空，直接返回；若为第一个节点，头删；否则找到节点并删除
	assert(ppFirst != NULL);
	SListNode *preDel = *ppFirst;
	SListNode *del = NULL;
	if (*ppFirst == NULL) return;
	else if (*ppFirst == pPos) SListPopFront(ppFirst);
	else
	{
		while(preDel->pNext != pPos && preDel != NULL)
		{
			preDel = preDel->pNext;
		}
		if (preDel != NULL)
		{
			del = preDel->pNext;
			preDel->pNext = del->pNext;
			free(del);
		}
	}
}

// 按值删除，只删遇到的第一个 
void SListRemove(SListNode **ppFirst, DataType data)
{
	assert(ppFirst != NULL);
	SListNode *cur = *ppFirst;
	SListNode *del = NULL;
	if (*ppFirst == NULL) return;
	else if (cur->data == data) SListPopFront(ppFirst);
	else
	{
		while (cur->pNext->data != data && cur != NULL)
		{
			cur = cur->pNext;
		}
		if (cur != NULL)
		{
			del = cur->pNext;
			cur->pNext = del->pNext;
			free(del);
		}
	}
}

// 按值删除，删除所有的 
void SListRemoveAll(SListNode **ppFirst, DataType data)
{
	//若链表为空，直接返回;否则进入循环，循环中若值为首节点，头删，否则删除后继续循环；
	assert(ppFirst != NULL);
	SListNode *cur = *ppFirst;
	SListNode *pre = NULL;
	if (*ppFirst == NULL) return;
	else
	{
		pre = cur;
		while (cur != NULL)
		{
			if (cur->data == data && cur == *ppFirst)
			{
				cur = cur->pNext;
				pre = cur;
				SListPopFront(ppFirst);
			}
			else if (cur->data == data)
			{
				pre->pNext = cur->pNext;
				free(cur);
				cur = pre->pNext;
				pre = cur;
			}
			else
				cur = cur->pNext;
		}
	}
}

// 销毁 
void SListDestroy(SListNode **ppFirst)
{
	assert(ppFirst != NULL);
	if (*ppFirst == NULL) return;
	else
	{
		while (*ppFirst != NULL)
		{
			SListPopBack(ppFirst);
		}
	}
}

// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
SListNode* SListFind(SListNode *pFirst, DataType data)
{
	if (pFirst == NULL) return NULL;
	else
	{
		while (pFirst != NULL)
		{
			if (pFirst->data == data) return pFirst;
			pFirst = pFirst->pNext;
		}
	}
	return NULL;
}

void showList(SListNode *pFirst)
{
	while (pFirst != NULL)
	{
		printf("%d-->", pFirst->data);
		pFirst = pFirst->pNext;
	}
	printf("NULL\n\n");
}

void testbitLList()
{
	SListNode *p;
	SListInit(&p);
	//尾插
	SListPushBack(&p, 1);
	SListPushBack(&p, 2); 
	SListPushBack(&p, 3);
	printf("NULL 尾插：");
	showList(p);
	//尾删
	SListPopBack(&p);
	SListPopBack(&p);
	SListPopBack(&p);
	printf("1-->2-->3-->NULL 尾删：");
	showList(p);
	//头插
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	printf("NULL 头插：");
	showList(p);
	//头删
	SListPopFront(&p);
	SListPopFront(&p);
	SListPopFront(&p);
	printf("4-->5-->6-->NULL 头删：");
	showList(p);
	//给定节点前插入
	SListInsert(&p, p, 2);
	SListInsert(&p, p->pNext, 2);
	SListInsert(&p, p->pNext, 3);
	printf("NULL 给定节点前插入：");
	showList(p);
	//给定节点删除
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	SListErase(&p, p->pNext);
	SListErase(&p, p->pNext);
	SListErase(&p, p);
	printf("4-->5-->6-->2-->3-->2-->NULL 给定节点删除：");
	showList(p);
	//销毁
	SListDestroy(&p);
	printf("销毁：\n\n");
	//给定值删除
	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	SListRemove(&p, 2);
	SListRemove(&p, 1);
	SListRemove(&p, 3);
	printf("1-->2-->3-->NULL  删2 给定值删除第一个：");
	showList(p);
	//给定值删除所有
	SListPushFront(&p, 2);
	SListPushFront(&p, 2);
	SListPushFront(&p, 2);
	SListRemoveAll(&p, 2);
	printf("2-->2-->2-->NULL  删2 给定值删除所有：");
	showList(p);
	//按置查找
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	SListInsert(&p, SListFind(p, 5),0);
	printf("4-->5-->6-->NULL  查5插0 按值查找插入：");
	showList(p);
	SListDestroy(&p);
}