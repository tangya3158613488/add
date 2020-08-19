#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//给定一棵满二叉树，判定该树是否为二叉搜索树，是的话打印True，不是的话打印False
/*
思路：1.首先从键盘输入数据，接收到vector的数组中
	  2.根据数组元素构建二叉树
	  3.判断该二叉树是否是二叉搜索树，就是根据该二叉树的中序遍历结果是否是有序的数组来判断
	  4.是二叉搜索树就打印True，否则打印False
*/
//构建二叉树结点
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{}
};
//通过数组构建二叉树
TreeNode* BuilTree(vector<int>& v)
{
	if (v.empty())
		return nullptr;
	queue<TreeNode**> q;
	TreeNode* root = nullptr;
	q.push(&root);
	for (int i = 0; i < v.size(); i++)
	{
		*q.front() = new TreeNode(v[i]);
		q.push(&((*q.front())->left));
		q.push(&((*q.front())->right));
		q.pop();
	}
	return root;
}
//中序遍历二叉树
void Inorder(vector<int>& num, TreeNode* root)
{
	if (root != nullptr)
	{
		Inorder(num, root->left);
		num.push_back(root->val);
		Inorder(num, root->right);
	}
}
//判断是否是二叉搜索树
bool IsBST(TreeNode* root)
{
	//中序遍历之后的数组是否有序
	vector<int> num;
	Inorder(num, root);
	for (int i = 1; i < num.size(); i++)
	{
		if (num[i - 1] > num[i])
			return false;
	}
	return true;
}
int main()
{
	vector<int> v;
	char c;
	int data;
	while (cin >> data)
	{
		v.push_back(data);
		cin >> c;
	}
	bool res = IsBST(BuilTree(v));
	if (res)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}
