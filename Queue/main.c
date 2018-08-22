#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void test()
{
	Queue q;
	InitQueue(&q);
	PushBack(&q, 1);
	PushBack(&q, 2);
	PushBack(&q, 3);
	printf("%d\n", getFront(&q));
	PopFront(&q);
	printf("%d\n", getFront(&q));
	PopFront(&q);
	printf("%d\n", getFront(&q));
	DestroyQueue(&q);
}

int main()
{
	test();
	system("pause");
	return 0;
}