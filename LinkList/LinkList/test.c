// LinkList.cpp: 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "LinkL.h"

void test()
{
	Node* plist;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	ShowLinkList(plist);
	int len = GetListLength(plist);
	printf("length: %d \n", len);
	PopBack(&plist);
	PopBack(&plist);
	ShowLinkList(plist);

	DestroyLinkList(&plist);
}

void TestPushFront()
{
	Node *plist = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	ShowLinkList(plist);
	PopFront(&plist);
	ShowLinkList(plist);
	DestroyLinkList(&plist);
}
void TestFind()
{
	Node *plist = NULL;
	Node *ret = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	ShowLinkList(plist);
	ret = Find(plist, 3);
	if (ret != NULL)
	{
		printf("%d\n", ret->data);
	}
	DestroyLinkList(&plist);
}
void TestInsert()
{
	Node *plist = NULL;
	Node *pos = NULL;
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 4);
	ShowLinkList(plist);
	Erase(&plist, Find(plist, 3));
	Insert(&plist, Find(plist, 3), 6);
	ShowLinkList(plist);
	DestroyLinkList(&plist);
}

void TestRemove()
{
	Node *plist = NULL;
	PushFront(&plist, 3);
	PushFront(&plist, 3);
	PushFront(&plist, 1);
	PushFront(&plist, 3);
	PushFront(&plist, 3);
	ShowLinkList(plist);
	RemoveAll(&plist, 3);
	ShowLinkList(plist);
	PrintTailToHead(plist);
	DestroyLinkList(&plist);
}
int main()
{
	TestRemove();
	//TestInsert();
	//TestFind();
	//TestPushFront();
	//test();
    return 0;
}

