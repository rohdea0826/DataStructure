#pragma once
/*	
	bitLinkList.hpp
	2018/9/12 23:31	Created By Rohdea
	���Գ���ΪtestbitLList()
	ps����Ŀ�ṹ�嶨��pNextӦ��ΪSListNode������ListNode�����Һ���Ӧ����SListNode������int
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



//����ʵ������Ĳ�������

// ֵ���� 
typedef int DataType;

typedef struct SListNode {
	DataType data; // ֵ 
	struct SListNode *pNext; // ָ����һ�����   //�ÿӰ�����Ŀ�����˸�S
} SListNode;

// ��ʼ�� 
void SListInit(SListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

// β������ 
void SListPushBack(SListNode** ppFirst, DataType data)
{
	//*ppFirstΪ��ֱ�Ӳ��룬������������һ���ǿսڵ���롣
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

// ͷ������ 
void SListPushFront(SListNode **ppFirst, DataType data)
{
	//��Ϊ�գ�ֱ�Ӳ��룻�����½ڵ�ָ��*ppFirst��*ppFirstָ���½ڵ㡣
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

// β��ɾ�� 
void SListPopBack(SListNode **ppFirst)
{
	//��*ppFirstΪ�գ�ֱ�ӷ��أ���ֻ��һ���ڵ㣬�ͷ��ÿգ�����ɾ��β�ڵ㡣
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

// ͷ��ɾ�� 
void SListPopFront(SListNode **ppFirst)
{
	//��Ϊ�գ�ֱ�ӷ��أ�����ɾ��ͷ���
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

// ���������룬���뵽���ǰ 
void SListInsert(SListNode **ppFirst, SListNode *pPos, DataType data)
{
	//�ٶ������ڵ�һ�������������С����׽ڵ�Ϊ�����ڵ㣬ͷ�壻�����ҵ��ڵ㲢���롣
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

// �������ɾ�� 
void SListErase(SListNode **ppFirst, SListNode *pPos)
{
	//�ٶ������ڵ�����������С�������Ϊ�գ�ֱ�ӷ��أ���Ϊ��һ���ڵ㣬ͷɾ�������ҵ��ڵ㲢ɾ��
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

// ��ֵɾ����ֻɾ�����ĵ�һ�� 
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

// ��ֵɾ����ɾ�����е� 
void SListRemoveAll(SListNode **ppFirst, DataType data)
{
	//������Ϊ�գ�ֱ�ӷ���;�������ѭ����ѭ������ֵΪ�׽ڵ㣬ͷɾ������ɾ�������ѭ����
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

// ���� 
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

// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
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
	//β��
	SListPushBack(&p, 1);
	SListPushBack(&p, 2); 
	SListPushBack(&p, 3);
	printf("NULL β�壺");
	showList(p);
	//βɾ
	SListPopBack(&p);
	SListPopBack(&p);
	SListPopBack(&p);
	printf("1-->2-->3-->NULL βɾ��");
	showList(p);
	//ͷ��
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	printf("NULL ͷ�壺");
	showList(p);
	//ͷɾ
	SListPopFront(&p);
	SListPopFront(&p);
	SListPopFront(&p);
	printf("4-->5-->6-->NULL ͷɾ��");
	showList(p);
	//�����ڵ�ǰ����
	SListInsert(&p, p, 2);
	SListInsert(&p, p->pNext, 2);
	SListInsert(&p, p->pNext, 3);
	printf("NULL �����ڵ�ǰ���룺");
	showList(p);
	//�����ڵ�ɾ��
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	SListErase(&p, p->pNext);
	SListErase(&p, p->pNext);
	SListErase(&p, p);
	printf("4-->5-->6-->2-->3-->2-->NULL �����ڵ�ɾ����");
	showList(p);
	//����
	SListDestroy(&p);
	printf("���٣�\n\n");
	//����ֵɾ��
	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	SListRemove(&p, 2);
	SListRemove(&p, 1);
	SListRemove(&p, 3);
	printf("1-->2-->3-->NULL  ɾ2 ����ֵɾ����һ����");
	showList(p);
	//����ֵɾ������
	SListPushFront(&p, 2);
	SListPushFront(&p, 2);
	SListPushFront(&p, 2);
	SListRemoveAll(&p, 2);
	printf("2-->2-->2-->NULL  ɾ2 ����ֵɾ�����У�");
	showList(p);
	//���ò���
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	SListInsert(&p, SListFind(p, 5),0);
	printf("4-->5-->6-->NULL  ��5��0 ��ֵ���Ҳ��룺");
	showList(p);
	SListDestroy(&p);
}