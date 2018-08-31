#include <stdio.h>
#include "BSTree.h"


void testBSTree()
{
	int tmp = 0;
	BSTree *root = NULL;
	BSTreeInsert(&root, 5);
	BSTreeInsert(&root, 2);
	BSTreeInsert(&root, 1);
	BSTreeInsert(&root, 4);
	BSTreeInsert(&root, 3);
	LDR(root);
	printf("\n");
	//tmp = BSTreeFind(root, 2);
	//printf("BSTreeFind:%d\n", tmp);
	//tmp = BSTreeFind_R(root, 2);
	//printf("BSTreeFind_R:%d\n", tmp);
	//tmp = BSTreeRemove(&root, 2);
	//printf("BSTreeRemove:%d\n", tmp);
	//LDR(root);
	//printf("\n");
	tmp = BSTreeRemove_R(&root, 2);
	printf("BSTreeRemove_R:%d\n", tmp);
	LDR(root);
	printf("\n");
}

int main()
{
	testBSTree();
	system("pause");
	return 0;
}