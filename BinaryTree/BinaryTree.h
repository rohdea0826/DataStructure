#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct BinaryTree
{
	DataType data;
	struct BinaryTree *LChild,*RChild
}BTree,*pBTree;

void InitBTree(pBTree pt);
void CreateBTree(pBTree pt);
int FindBTree(BTree t);