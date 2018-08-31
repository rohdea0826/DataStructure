#pragma once
#include <stdlib.h>

typedef int DataType;

typedef struct BSTreeNode
{
	DataType key;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}BSTree;

//中序遍历输出
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

//非递归
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
			//重复了，插入失败
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


//删除
//1.左为空--要删除的是根--要删除的是parent的左/右
//2.右为空--类似左为空
//3.左右都不为空--用左子树的最大值替换

//先查后删
//成功返回1，失败返回-1；
int BSTreeRemove(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;
	while (cur != NULL)
	{
		if (key == cur->key)
		{
			//找到了，在此删除
			//找到的节点左子树为空
			if (cur->left == NULL)
			{
				//根节点，
				if (parent == NULL)
					*root = cur->right;
				else if (key > parent->key)
					parent->right = cur->right;
				else
					parent->left = cur->right;
				free(cur);
			}
			//找到的节点右子树为空
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
			//左右子树均不为空
			else
			{
				//左子树中找最大的替换
				BSTreeNode *del = cur->left;
				BSTreeNode *delParent = NULL;
				while (del->right != NULL)
				{
					delParent = del;
					del = del->right;
				}
				//找到最大的首先将值替换过来
				//然后考虑最大结点的左子树
				cur->key = del->key;
				//若左子树中最大值节点的父节点就是要删除的节点
				//将其左子树交给要删除的节点
				if (delParent == NULL)
					cur->left = del->left;
				//否则将其交给父节点
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

//递归删除
//判断基本和非递归一样，只是因为传递的是*root的地址，会有略微差异
int BSTreeRemove_R(BSTreeNode **root, DataType key)
{
	BSTreeNode *del = *root;
	//若树为空，返回失败
	if ((*root) == NULL)
		return -1;
	//若在树中找到了值为key的节点，进入处理
	if (key == (*root)->key)
	{
		//若找到的节点的左子树为空，将该节点指向其右子树
		if ((*root)->left == NULL)
			*root = (*root)->right;
		//若找到的节点的右子树为空，将该节点指向其左子树
		else if ((*root)->right == NULL)
			*root = (*root)->left;
		//当找到的节点的左右子树均不为空，
		//找到其左子树中最大的值或右子树中最小的值并替换
		//这样不会影响整棵树的大致结构
		//判断方法同非递归删除
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

