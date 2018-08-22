#include <stdio.h>
#include "Stack.h"

void test()
{
	Stack s;
	InitialStack(&s);
	PushStack(&s, 0);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	ShowStack(&s);
	printf("\n");
	PopStack(&s);
	PopStack(&s);
	PopStack(&s);
	printf("%d\n", GetTop(&s));
	printf("%d\n", GetTop(&s));
	ShowStack(&s);
	DestroyStack(&s);
}

int main()
{
	test();
	system("pause");
	return 0;
}