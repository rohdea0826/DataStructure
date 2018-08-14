#define _CRT_NO_SECURE_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX 10

typedef int DataType;

typedef struct SeqList
{
	DataType *data;
	int sz;
	int capacity;
}SeqList,*pSeqList;

void InitSeqList(pSeqList ps);
void checkCapacity(pSeqList ps);
void PushBack(pSeqList ps, DataType d);
void PopBack(pSeqList ps);
void PushFront(pSeqList ps, DataType d);
void PopFront(pSeqList ps);
void showSeqList(SeqList p);