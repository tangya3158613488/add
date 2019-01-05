#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
int main()
{
	char a[] = "ABD##E#H##CF##G##";
	int index = 0;
	BTNode* tree = BinaryTreeCreate(a,&index);
	BinaryTreePreorder(tree);
	printf("\n");
	BinaryTreeInorder(tree);
	printf("\n");
	BinaryTreePostorder(tree);
	printf("\n");
	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeLevelkSize(tree,4));
	BinaryTreeDestory(tree);
	tree = NULL;
	return 0;
}