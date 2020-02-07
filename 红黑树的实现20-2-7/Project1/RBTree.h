#pragma once
#include<iostream>

using std::cout;
using std::endl;

enum Color
{
	RED,
	BLACK
};
template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _color(color)
	{}
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _color;
};
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
		:_root(nullptr)
	{}
	~RBTree()
	{
		Destroy(_root);
	}
	bool Insert(const T& data)
	{
		//��һ�������ն����������ķ�ʽ�����½��
		if (nullptr == _root)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return true;
		}
		else
		{
			//���ն��������������ԣ��ں�������ҵ�Ҫ�����λ��
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (data < cur->_data)
				{
					parent = cur;
					cur = cur->_left;
				}	
				else if (data > cur->_data)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					return false;
			}
			//�����½��
			cur = new Node(data);
			cur->_color = RED;
			if (data < parent->_data)
			{
				parent->_left = cur;
				cur->_parent = parent;
			}	
			else
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			
			//�ڶ���������½�����󣬺�����������Ƿ��⵽�ƻ�������������ֱ���˳�������Ժ����������ת��ɫ����
			while (parent && RED == parent->_color)
			{
				//��ʱgrandfatherһ�����ڣ���Ϊparent���ڣ�����ɫ���Ǻ�ɫ����parentһ�����Ǹ�
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
							std::swap(cur, parent);
						}
						grandfather->_color = RED;
						parent->_color = BLACK;
						RotateR(grandfather);
						break;
					}
				}
				//parent���Ҳ�����
				else
				{
					Node* uncle = grandfather->_left;
					if (uncle && RED == uncle->_color)
					{
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_left)
						{
							RotateR(parent);
							std::swap(cur, parent);
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
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		Node* pparent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left == parent)
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
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	void _Inorder(Node* root)
	{
		if (root)
		{
			_Inorder(root->_left);
			cout << root->_data << " ";
			_Inorder(root->_right);
		}
	}
	void Destroy(Node* root)
	{
		if (root)
		{
			Destroy(root->_left);
			Destroy(root->_right);
			root = nullptr;
		}
	}
private:
	Node* _root;
};
void TestRBTree()
{
	RBTree<int> rt1;
	rt1.Insert(2);
	rt1.Insert(8);
	rt1.Insert(11);
	rt1.Insert(13);
	rt1.Insert(17);
	rt1.Insert(15);
	rt1.Inorder();
}