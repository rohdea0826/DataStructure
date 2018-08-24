#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct BinaryTree
{
	DataType data;
	struct BinaryTree *LChild, *RChild;
}BTree,*pBTree;

pBTree CreateNode(DataType d);
pBTree CreateBTree(DataType preOrder[], int size, int *UsedSize);
void preOrder(pBTree t);
void midOrder(pBTree t);
