#include "Queue.h"

void InitQueue(pQueue q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void PushBack(pQueue q, DataType d)
{
	QueueNode *newNode = (pQueueNode)malloc(sizeof(QueueNode));
	newNode->data = d;
	newNode->next = NULL;
	if (q->front == NULL)
	{
		q->front = newNode;
		q->rear = newNode;
		q->size++;
		return;
	}
	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}

int PopFront(pQueue q)
{
	if (q->front == NULL)
	{
		q->rear = NULL;
		return -1;
	}
	pQueueNode del = q->front;
	q->front = q->front->next;
	q->size--;
	free(del);
	del = NULL;
	return 1;
}

DataType getFront(pQueue q)
{
	assert(q->front != NULL);
	return q->front->data;
}

void DestroyQueue(pQueue q)
{
	while (q->front != NULL)
	{
		PopFront(q);
	}
}
