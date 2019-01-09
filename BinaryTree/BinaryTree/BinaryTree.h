#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* a,int *pindex);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelkSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreePreorder(BTNode* root);//先序遍历
void BinaryTreeInorder(BTNode* root);//中序遍历
void BinaryTreePostorder(BTNode* root);//后序遍历
void BinaryTreeLevelOrder(BTNode* root);//层序遍历
void BinaryTreeComplete(BTNode* root);//判断二叉树是否是完全二叉树
