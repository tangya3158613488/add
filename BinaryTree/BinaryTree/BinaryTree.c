#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
BTNode* BinaryTreeCreate(BTDataType* a, int *pindex)
{
	assert(a);
	if (a[*pindex] == '#')
	{
		++(*pindex);
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pindex];
		++(*pindex);
		root->_left = BinaryTreeCreate(a, pindex);
		root->_right = BinaryTreeCreate(a, pindex);
		return root;
	}
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}
}

int BinaryTreeLeafSize(BTNode* root)
{
	
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelkSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelkSize(root->_left, k - 1) + BinaryTreeLevelkSize(root->_right, k - 1);
}
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->_data == x)
//		return root;
//	BTNode* ret;
//	ret=BinaryTreeFind(root->_left, x);
//	if (ret)
//		return ret;
//	ret = BinaryTreeFind(root->_right, x);
//	if (ret)
//		return ret;
//	return NULL;
//}

void BinaryTreePreorder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePreorder(root->_left);
	BinaryTreePreorder(root->_right);
}
void BinaryTreeInorder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInorder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInorder(root->_right);
}

void BinaryTreePostorder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostorder(root->_left);
	BinaryTreePostorder(root->_right);
	printf("%c ", root->_data);
}