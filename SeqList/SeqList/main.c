// SeqList.cpp: 定义控制台应用程序的入口点。
//
#define _CRT_NO_SECURE_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "SeqList.h"

void test()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	showSeqList(seq);
}

int main()
{
	test();
    return 0;
}

