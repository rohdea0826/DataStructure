#include "Stack.h"

//显示整个栈
void ShowStack(Stack * s)
{
	ptrStackNode a = s->top;
	if (a == NULL)
	{
		printf("NULL");
		return;
	}
	while (a != NULL)
	{
		printf("%d-->", a->data);
		a = a->next;
	}
	printf("NULL");
}

void InitialStack(Stack * s)
{
	s->top = NULL;
	s->count = 0;
}
//入栈
void PushStack(Stack *s,DataType a)
{
	ptrStackNode newNode = (ptrStackNode)malloc(sizeof(StackNode));
	newNode->data = a;
	newNode->next = s->top;
	s->top = newNode;
	s->count++;
}
//出栈并返回当前栈顶元素
int PopStack(Stack* s)
{
	if (s->top == NULL) return -1;
	Stack* del = s->top;
	s->top = s->top->next;
	s->count--;
	free(del);
	del = NULL;
	return 1;
}

DataType GetTop(Stack* s)
{
	assert(s->top != NULL);
	return s->top->data;
}

void DestroyStack(Stack * s)
{
	while (s->count != 0)
	{
		PopStack(s);
	}
}
