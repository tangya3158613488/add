#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
enum Color
{
	RED,
	BLACK
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K,V>* _left;
	RBTreeNode<K,V>* _right;
	RBTreeNode<K,V>* _parent;
	pair<K,V> _kv;
	Color _color;
	RBTreeNode(const pair<K,V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _color(RED)
	{}
};
template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}
	
	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = BLACK;
			return true;
		}
		else
		{
			Node* cur = _root;
			Node* parent = nullptr;
			//�ں�������ҵ����Ҫ�����λ��
			while (cur)
			{
				if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			//�����½��
			cur = new Node(kv);
			cur->_color = RED;//�²��������ɫ�趨Ϊ��ɫ
			if (kv.first < parent->_kv.first)
			{
				cur = parent->_left;
				cur->_parent = parent;
			}
			else
			{
				cur = parent->_right;
				cur->_parent = parent;
			}
			//����½�����󣬺�����������Ƿ��⵽�ƻ�
			//��Ϊ�½���Ĭ����ɫ�Ǻ�ɫ����ˣ������˫�׽�����ɫ�Ǻ�ɫ��û��Υ������������ʣ�����Ҫ������
			//�����²������˫�׽���Ǻ�ɫʱ����Υ��������������������һ��ĺ�ɫ��㣬��ʱ��Ҫ�Ժ������������ۣ�
			while (parent && RED == parent->_color)
			{
				//��ʱgrandfatherһ�����ڣ���Ϊparent���ڣ��Ҳ��Ǻ�ɫ��㣬��parentһ�����Ǹ�
				Node* grandfather = parent->_parent;
				//parent���������
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					if (uncle && RED == uncle->_color)
					{
						//�����������Ϊ��ɫ
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						//�����㲻���ڣ��������������Ϊ��ɫ
						if (cur == parent->_right)
						{
							RotateL(parent);
							swap(cur, parent);
						}
						grandfather->_color = RED;
						parent->_color = BLACK;
						RotateR(grandfather);
					}
				}
				//parent���Ҳ�����
				else
				{
					Node* uncle = grandfather->_right;
					if (uncle && RED == uncle->_color)
					{
						//�����������Ϊ��ɫ
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						//�����㲻���ڣ��������������Ϊ��ɫ
						if (cur == parent->_left)
						{
							RotateR(parent);
							swap(cur,parent);
						}
						RotateL(grandfather);
						grandfather->_color = RED;
						parent->_color = BLACK;
						break;
					}
				}
			}
			_root->_color = BLACK;
			return true;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left = parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}
		subL->_parent = pparent;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}
		subR->_parent = pparent;
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	void Destroy(Node* root)
	{
		if (root)
		{
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << " ";
		_Inorder(root->_right);
	}
	Node* _root;
};
void TestRBTree()
{
	RBTree<int, int> t;
	t.Insert(make_pair(1,1));
	t.Insert(make_pair(3,3));
	/*t.Insert(make_pair(2,2));
	t.Insert(make_pair(5,5));*/

	t.Inorder();
}