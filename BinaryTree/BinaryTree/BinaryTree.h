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
void BinaryTreePreorder(BTNode* root);//�������
void BinaryTreeInorder(BTNode* root);//�������
void BinaryTreePostorder(BTNode* root);//�������
void BinaryTreeLevelOrder(BTNode* root);//�������

