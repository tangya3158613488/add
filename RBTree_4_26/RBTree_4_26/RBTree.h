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
			//在红黑树中找到结点要插入的位置
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
			//插入新结点
			cur = new Node(kv);
			cur->_color = RED;//新插入结点的颜色设定为红色
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
			//检测新结点插入后，红黑树的性质是否遭到破坏
			//因为新结点的默认颜色是红色，因此：如果其双亲结点的颜色是黑色，没有违反红黑树的性质，不需要调整；
			//但当新插入结点的双亲结点是红色时，就违反了性质三不能有连在一起的红色结点，此时需要对红黑树分情况讨论：
			while (parent && RED == parent->_color)
			{
				//此时grandfather一定存在，因为parent存在，且不是黑色结点，则parent一定不是根
				Node* grandfather = parent->_parent;
				//parent在左侧的情况
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					if (uncle && RED == uncle->_color)
					{
						//叔叔结点存在且为红色
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						//叔叔结点不存在，或叔叔结点存在且为黑色
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
				//parent在右侧的情况
				else
				{
					Node* uncle = grandfather->_right;
					if (uncle && RED == uncle->_color)
					{
						//叔叔结点存在且为红色
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						//叔叔结点不存在，或叔叔结点存在且为黑色
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