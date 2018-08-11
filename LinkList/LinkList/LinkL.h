#ifndef __LINKL_H__
#define __LINKL_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node;


void InitLinkList(Node** pplist);
void DestroyLinkList(Node** pplist);
void PushBack(Node** pplist, DataType d);
void PopBack(Node** pplist);
void PushFront(Node** pplist, DataType d);
void PopFront(Node** pplist);

void ShowLinkList(Node* plist);
int GetListLength(Node *plist);

Node* Find(Node *plist, DataType d);
void Insert(Node **pplist, Node *pos, DataType d);
void Erase(Node **pplist, Node *pos);
void Remove(Node **pplist, DataType d);
void RemoveAll(Node **pplist, DataType d);
void PrintTailToHead(Node* plist);

#endif