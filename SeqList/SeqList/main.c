// SeqList.cpp: 定义控制台应用程序的入口点。
//
#define _CRT_NO_SECURE_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "SeqList.h"

void testPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PopBack(&seq);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testPushFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	showSeqList(seq);
	PopFront(&seq);
	showSeqList(seq);
	PopFront(&seq);
	showSeqList(seq);
	PopFront(&seq);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testInsert()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	InsertList(&seq, 1, 4);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testRemove()
{
	SeqList seq;
	InitSeqList(&seq);
	//PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	Remove(&seq, 2);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testRemovAll()
{
	SeqList seq;
	InitSeqList(&seq);
	//PushFront(&seq, 2);
	//PushFront(&seq, 3);
	//PushFront(&seq, 1);
	//PushFront(&seq, 2);
	//PushFront(&seq, 1);
	PushFront(&seq, 1);
	RemoveAll(&seq, 1);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testFindList()
{
	SeqList seq;
	int tmp;
	InitSeqList(&seq);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	tmp = FindList(&seq, 1);
	printf("%d\n", tmp);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testBubbleSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	BubbleSort(&seq);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testSelectSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	SelectSort(&seq);
	showSeqList(seq);
	DestroySeqList(&seq);
}

void testBinarySearch()
{
	SeqList seq;
	int tmp;
	InitSeqList(&seq);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	SelectSort(&seq);

	tmp = BinarySearch(&seq, 3);
	printf("%d\n", tmp);

	showSeqList(seq);
	DestroySeqList(&seq);
}

int main()
{
	testBinarySearch();
	//testSelectSort();
	//testBubbleSort();
	//testFindList();
	//testRemovAll();
	//testRemove();
	//testInsert();
	//testPushFront();
	//testPushBack();
    return 0;
}

