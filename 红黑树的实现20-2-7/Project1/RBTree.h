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
		//第一步：按照二叉搜索树的方式插入新结点
		if (nullptr == _root)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return true;
		}
		else
		{
			//按照二叉搜索树的特性，在红黑树中找到要插入的位置
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
			//插入新结点
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
			
			//第二步：检测新结点插入后，红黑树的性质是否遭到破坏，若满足性质直接退出，否则对红黑树进行旋转着色处理
			while (parent && RED == parent->_color)
			{
				//此时grandfather一定存在，因为parent存在，且颜色不是黑色，则parent一定不是根
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
							std::swap(cur, parent);
						}
						grandfather->_color = RED;
						parent->_color = BLACK;
						RotateR(grandfather);
						break;
					}
				}
				//parent在右侧的情况
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
							std::swap(parent, cur);
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
	bool IsRBtree()
	{
		//空树也是红黑树
		if (nullptr == _root)
			return true;
		//检测根节点是否满足红黑树的性质
		if (BLACK != _root->_color)
		{
			cout << "违反红黑树性质：根节点必须为黑色" << endl;
			return false;
		}
		//获取任意一条路径中黑色结点的个数
		size_t blackCount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (BLACK == cur->_color)
				blackCount++;
			cur = cur->_left;
		}
		size_t k = 0;//k用来记录路径中黑色结点的个数
		return _IsRBTree(_root, k, blackCount);
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
	bool _IsRBTree(Node* root, size_t k, const size_t blackCount)
	{
		if (nullptr == root)
			return true;
		//统计黑色结点的个数
		if (BLACK == root->_color)
			k++;
		//检测当前结点与其双亲结点是否都为红色
		Node* parent = root->_parent;
		if (parent && RED == parent->_color && RED == root->_color)
		{
			cout << "违反红黑树性质：没有连在一起的红色结点" << endl;
			return false;
		}
		//检测当前路径中黑色结点的个数是否与其他路径中的黑色结点相等
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (k != blackCount)
			{
				cout << "违反红黑树性质：每条路径中黑色结点的个数必须相等" << endl;
				return false;
			}
		}
		return _IsRBTree(root->_left, k, blackCount) && _IsRBTree(root->_right, k, blackCount);
	}
private:
	Node* _root;
};
void TestRBTree()
{
	RBTree<int> rt1;
	rt1.Insert(16);
	rt1.Insert(3);
	rt1.Insert(7);
	rt1.Insert(11);
	rt1.Insert(9);
	rt1.Insert(26);
	rt1.Insert(18);
	rt1.Insert(14);
	rt1.Insert(30);
	rt1.Insert(20);
	rt1.Inorder();
	rt1.IsRBtree();
}