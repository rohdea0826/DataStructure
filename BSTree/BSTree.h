#pragma once
#include <stdlib.h>

typedef int DataType;

typedef struct BSTreeNode
{
	DataType key;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}BSTree;

//����������
void LDR(BSTreeNode *root)
{
	if (root->left != NULL)
		LDR(root->left);
	printf("%d ", root->key);
	if (root->right != NULL)
		LDR(root->right);
}

int BSTreeFind_R(const BSTreeNode *root, DataType key)
{
	if (root == NULL)
		return -1;
	if (key == root->key)
		return 1;
	else if(key > root->key)
		return BSTreeFind_R(root->right, key);
	else
		return BSTreeFind_R(root->left, key);
	return 1;
}

//�ǵݹ�
int BSTreeFind(BSTreeNode *root, DataType key)
{
	BSTreeNode *cur = root;
	while (cur != NULL)
	{
		if (key == cur->key)
			return 1;
		else if (key > cur->key)
			cur = cur->right;
		else
			cur = cur->left;
	}
	return -1;
}

int BSTreeInsert(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	while (cur != NULL)
	{
		if (key == cur->key)
			//�ظ��ˣ�����ʧ��
		{
			return -1;
		}
		parent = cur;
		if (key > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}

	}
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->key = key;
	node->left = node->right = NULL;

	if (parent == NULL)
	{
		*root = node;
		return 1;
	}

	if (key > parent->key)
	{
		parent->right = node;
	}
	else
	{
		parent->left = node;
	}
	return 1;
}

int BSTreeInsert_R(BSTreeNode **root, DataType key)
{
	if (*root == NULL)
	{
		BSTreeNode *node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = node->right = NULL;
		*root = node;
		return 1;
	}
	if (key > (*root)->key)
		return BSTreeInsert_R(&(*root)->right, key);
	else
		return BSTreeInsert_R(&(*root)->left, key);
	return -1;
}


//ɾ��
//1.��Ϊ��--Ҫɾ�����Ǹ�--Ҫɾ������parent����/��
//2.��Ϊ��--������Ϊ��
//3.���Ҷ���Ϊ��--�������������ֵ�滻

//�Ȳ��ɾ
//�ɹ�����1��ʧ�ܷ���-1��
int BSTreeRemove(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	while (cur != NULL)
	{
		if (key == cur->key)
		{
			//�ҵ��ˣ��ڴ�ɾ��
			//�ҵ��Ľڵ�������Ϊ��
			if (cur->left == NULL)
			{
				//���ڵ㣬
				if (parent == NULL)
					*root = cur->right;
				else if (key > parent->key)
					parent->right = cur->right;
				else
					parent->left = cur->right;
				free(cur);
			}
			//�ҵ��Ľڵ�������Ϊ��
			else if (cur->right == NULL)
			{
				if (parent = NULL)
					*root = cur->left;
				if (key > parent->key)
					parent->right = cur->left;
				else
					parent->left = cur->left;
				free(cur);
			}
			//������������Ϊ��
			else
			{
				//���������������滻
				BSTreeNode *del = cur->left;
				BSTreeNode *delParent = NULL;
				while (del->right != NULL)
				{
					delParent = del;
					del = del->right;
				}
				//�ҵ��������Ƚ�ֵ�滻����
				//Ȼ����������������
				cur->key = del->key;
				//�������������ֵ�ڵ�ĸ��ڵ����Ҫɾ���Ľڵ�
				//��������������Ҫɾ���Ľڵ�
				if (delParent == NULL)
					cur->left = del->left;
				//�����佻�����ڵ�
				else
					delParent->right = del->left;
				free(del);
			}
			return 1;
		}
		parent = cur;
		if (key < cur->key)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return -1;
}

//�ݹ�ɾ��
//�жϻ����ͷǵݹ�һ����ֻ����Ϊ���ݵ���*root�ĵ�ַ��������΢����
int BSTreeRemove_R(BSTreeNode **root, DataType key)
{
	BSTreeNode *del = *root;
	//����Ϊ�գ�����ʧ��
	if ((*root) == NULL)
		return -1;
	//���������ҵ���ֵΪkey�Ľڵ㣬���봦��
	if (key == (*root)->key)
	{
		//���ҵ��Ľڵ��������Ϊ�գ����ýڵ�ָ����������
		if ((*root)->left == NULL)
			*root = (*root)->right;
		//���ҵ��Ľڵ��������Ϊ�գ����ýڵ�ָ����������
		else if ((*root)->right == NULL)
			*root = (*root)->left;
		//���ҵ��Ľڵ��������������Ϊ�գ�
		//�ҵ���������������ֵ������������С��ֵ���滻
		//��������Ӱ���������Ĵ��½ṹ
		//�жϷ���ͬ�ǵݹ�ɾ��
		else
		{
			BSTreeNode *delparent = NULL;
			del = del->left;
			while (del->right != NULL)
			{
				delparent = del;
				del = del->right;
			}
				(*root)->key = del->key;
			if (delparent == NULL)
				(*root)->left = del->left;
			else
				delparent->right = del->left;
		}
		free(del);
		return 1;
	}
	if (key < (*root)->key)
		return BSTreeRemove_R(&(*root)->left, key);
	else
		return BSTreeRemove_R(&(*root)->right, key);
}

