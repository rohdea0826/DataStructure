#define _CRT_NO_SECURE_WARNINGS 1
//运行环境：VS2017	平台：x86

//该程序是为了熟悉线性表而建
//使用c语言编写，较为简陋，如有错误之处还望指正
//重新造轮子的目的是为了更好的理解轮子
//后续可能还会使用C++中的模板来模拟实现STL中的vector

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

