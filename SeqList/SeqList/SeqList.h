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
void InsertList(pSeqList ps, int pos, DataType d);
void Remove(pSeqList ps, DataType d);
void RemoveAll(pSeqList ps, DataType d);
int  FindList(pSeqList ps, DataType d);
void BubbleSort(pSeqList ps);
void SelectSort(pSeqList ps);
//ÉÏÃæµÄOK
int  BinarySearch(pSeqList ps, DataType d);
void showSeqList(SeqList p);
void DestroySeqList(pSeqList p);