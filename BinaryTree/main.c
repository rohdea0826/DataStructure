#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void test()
{
	int VLR[] = { 1,2,-1,-1,3,-1,4,5 };
	int size = 8;
	int UsedSize = 0;
	pBTree root = CreateBTree(VLR, size, &UsedSize);

}

int main()
{
	test();
	return 0;
}