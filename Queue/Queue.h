#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct QueueNode1
{
	DataType data;
	struct QueueNode1 *next;
}QueueNode,*pQueueNode;

typedef struct Queue
{
	pQueueNode front;
	pQueueNode rear;
	int size;
}*pQueue,Queue;

void InitQueue(pQueue q);
void PushBack(pQueue q, DataType d);
int PopFront(pQueue q);
DataType getFront(pQueue q);
void DestroyQueue(pQueue q);