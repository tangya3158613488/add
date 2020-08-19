#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//����һ�������������ж������Ƿ�Ϊ�������������ǵĻ���ӡTrue�����ǵĻ���ӡFalse
/*
˼·��1.���ȴӼ����������ݣ����յ�vector��������
	  2.��������Ԫ�ع���������
	  3.�жϸö������Ƿ��Ƕ��������������Ǹ��ݸö������������������Ƿ���������������ж�
	  4.�Ƕ����������ʹ�ӡTrue�������ӡFalse
*/
//�������������
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
//ͨ�����鹹��������
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
//�������������
void Inorder(vector<int>& num, TreeNode* root)
{
	if (root != nullptr)
	{
		Inorder(num, root->left);
		num.push_back(root->val);
		Inorder(num, root->right);
	}
}
//�ж��Ƿ��Ƕ���������
bool IsBST(TreeNode* root)
{
	//�������֮��������Ƿ�����
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
