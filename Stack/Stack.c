#include "Stack.h"

//��ʾ����ջ
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
//��ջ
void PushStack(Stack *s,DataType a)
{
	ptrStackNode newNode = (ptrStackNode)malloc(sizeof(StackNode));
	newNode->data = a;
	newNode->next = s->top;
	s->top = newNode;
	s->count++;
}
//��ջ�����ص�ǰջ��Ԫ��
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
