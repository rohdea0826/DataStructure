#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct LinkStack
{
	DataType data;
	struct LinkStack *next;
}*ptrStackNode,StackNode ; 

typedef struct Stack
{
	ptrStackNode top;
	int count;
}Stack;

void ShowStack(Stack* s);

void InitialStack(Stack* s);

void PushStack(Stack* s,DataType a);

int PopStack(Stack* s);

DataType GetTop(Stack* s);

void DestroyStack(Stack* s);