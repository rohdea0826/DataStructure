#include "BinaryTree.h"

pBTree CreateNode(DataType d)
{
	pBTree NewNode = (pBTree)malloc(sizeof(BTree));
	NewNode->data = d;
	NewNode->LChild = NewNode->RChild = NULL;
	return NewNode;
}

pBTree CreateBTree(DataType preOrder[], int size, int * UsedSize)
{
	if (size <= 0)
	{
		*UsedSize = 0;
		return NULL;
	}

	if (preOrder[0] == -1)
	{
		*UsedSize = 1;
		return NULL;
	}

	int LeftUsed, RightUsed;
	BTree *root = CreateNode(preOrder[0]);
	root->LChild = CreateBTree(preOrder + 1, size - 1, &LeftUsed);
	root->RChild = CreateBTree(preOrder + 1 + LeftUsed, size - 1 - LeftUsed, &RightUsed);
	*UsedSize = 1+LeftUsed + RightUsed;
	return root;
}

void preOrder(pBTree t)
{
	if (t == NULL) return;
	else
	{
		printf("%d ", t->data);
	}
	preOrder(t->LChild);
	preOrder(t->RChild);
}

void midOrder(pBTree t)
{
	preOrder(t->LChild);
	if (t == NULL) return;
	else
	{
		printf("%d ", t->data);
	}
	preOrder(t->RChild);
}