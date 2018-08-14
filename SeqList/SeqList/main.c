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

int main()
{
	testPushFront();
	//testPushBack();
    return 0;
}

