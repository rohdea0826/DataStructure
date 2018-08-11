#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkL.h"

void InitLinkList(Node ** pplist)
{
	assert(pplist != NULL);
	*pplist = NULL;
}

void DestroyLinkList(Node ** pplist)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(pplist);
	cur = *pplist;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}

Node* BuyNode(DataType d)
{
	Node* ptr = (Node *)malloc(sizeof(Node));
	if (ptr == NULL)
	{
		perror("PushBack::mallloc()");
	}
	ptr->data = d;
	ptr->next = NULL;
	return ptr;
}

void PushBack(Node ** pplist, DataType d)
{
	
	Node *newNode = BuyNode(d);
	assert(pplist != NULL);
	//无节点
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else	//有节点
	{
		Node* cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
	
}

void PopBack(Node ** pplist)
{
	Node *cur = NULL;
	assert(pplist);
	cur = *pplist;
	if (*pplist == NULL) return;
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void PushFront(Node ** pplist, DataType d)
{
	assert(pplist != NULL);
	Node *newNode = BuyNode(d);
	//链表是否为空不影响头插的方式,无需判断。
	newNode->next = *pplist;
	*pplist = newNode;
}

void PopFront(Node ** pplist)
{
	assert(pplist != NULL);
	if (*pplist == NULL) return;
	Node *del = *pplist;
	(*pplist) = (*pplist)->next;
	free(del);
}

void ShowLinkList(Node* plist)
{
	Node * cur = plist;
	while (cur!=NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

int GetListLength(Node * plist)
{
	int ret = 0;
	while (plist != NULL)
	{
		ret++;
		plist = plist->next;
	}
	return ret++;
}

Node * Find(Node * plist, DataType d)
{
	Node *cur = plist;
	while (cur)
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void Insert(Node ** pplist, Node * pos, DataType d)
{
	Node *prev = *pplist;
	assert(pplist != NULL);
	//要插入的地址为空或链表为空，返回
	if (pos ==NULL || *pplist == NULL) return;
	//要插入的地址为第一个元素地址，头插
	if (*pplist == NULL || *pplist == pos)
	{
		PushFront(pplist, d);
		return;
	}
	//找pos位置的前一个元素，若找到了，pos前插入元素，否则不做处理
	while (prev->next != pos && prev)
	{
		prev = prev->next;
	}
	if (prev!=NULL)
	{
		Node *newNode = BuyNode(d);
		newNode->next = pos;
		prev->next = newNode;
	}
}

void Erase(Node ** pplist, Node * pos)
{
	assert(pplist);
	//若链表为空或要删除的地址为空，返回
	if (*pplist == NULL || pos == NULL) return;
	//要插入的地址为第一个元素，头删
	if (pos == *pplist)
	{
		PopFront(pplist);
		return;
	}
	Node *prev = *pplist;
	//若找到要删除元素的前一个元素，删除，否则不做处理
	while (prev && prev->next != pos)
	{
		prev = prev->next;
	}
	if (prev != NULL)
	{
		prev->next = pos->next;
		free(pos);
	}
}

void Remove(Node ** pplist, DataType d)
{
	assert(pplist);

	//if (*pplist == NULL) return;
	//Erase(pplist, Find(*pplist, d));

	Node *cur = NULL;
	Node *prev = NULL;
	if (*pplist == NULL) return;
	cur = *pplist;
	
	while (cur)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)
			{
				*pplist = (*pplist)->next;
				free(cur);
				cur = NULL;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}

void RemoveAll(Node ** pplist, DataType d)
{
	assert(pplist);
	if (*pplist == NULL) return;
	Node *cur = NULL;
	Node *prev = NULL;
	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)
			{
				*pplist = (*pplist)->next;
				free(cur);
				cur = *pplist;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
//
//void PrintTailToHead(Node * plist)
//{
//	//递归
//	if (plist == NULL) return;
//	PrintTailToHead(plist->next);
//	printf("%d-->", plist->data);
//}

void PrintTailToHead(Node* plist)
{
	Node *cur = NULL;
	Node *tail = NULL;
	cur = plist;
	while (tail != plist)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d-->", cur->data);
		tail = cur;
	}
}


