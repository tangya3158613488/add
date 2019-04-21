#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//template<class K, class V>
//struct pair
//{
//	K first;
//	V second;
//	pair(const K& k, const V& v)
//		: first(k)
//		, second(v)
//	{}
//};
//template<class K, class V>
//inline std::pair<K,V> make_pair(const K& k, const V& v)
//{
//	 
//	return std::pair(k, v);
//}
//AVL树结点的定义
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	K _key;
	V _value;
	int _bf;
	AVLTreeNode(const K& key,const V& value)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _key(key)
		, _value(value)
		, _bf(0)
	{}
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}
	
	~AVLTree()
	{
		Destroy(_root);
	}

	bool Insert(const K& key,const V& value)
	{
		//如果树为空，插入新结点
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}
		//按照二叉搜索树的性质找到要插入的位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
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
		cur = new Node(key,value);
		if (key < parent->_key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		//更新cur的父亲结点
		cur->_parent = parent;

		//插入新结点后，AVL树的平衡性可能遭到破坏，此时需要更新平衡因子，并检查是否破坏了AVL树的平衡性
		/*1.调节平衡因子
		1)如果cur插入到parent的左侧，给parent的平衡因子-1；
		2)如果cur插入到parent的右侧，给parent的平衡因子+1
		此时parent的平衡因子可能是：0、正负1、正负2
		如果parent的平衡因子是0，说明插入之前parent的平衡因子为正负1，插入后被调整成0，此时满足AVL数的性质，插入成功。
		如果parent的平衡因子是正负1，说明插入前parent的平衡因子一定为0，插入后更新成正负1，此时以parent为根的树的高度增加，需要继续向上更新。
		如果parent的平衡因子为正负2，则parent的平衡因子违反了平衡树的性质，需要对其进行旋转处理，以降低高度。
		*/
		while (parent)
		{
			//更新父亲的平衡因子
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			//更新后检查父亲的平衡
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				//向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//插入新结点后，AVL数的平衡性遭到破坏，需要对以parent为根的树进行旋转处理
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)//左右双旋
				{
					Node* subL = parent->_left;
					Node* subLR = subL->_right;
					int bf = subLR->_bf;
					RotateL(parent->_left);
					RotateR(parent);
					if (bf == -1)
					{
						parent->_bf = 1;
						subL->_bf = 0;
					}
					else if (bf == 1)
					{
						parent->_bf = 0;
						subL->_bf = -1;
					}
					else
					{
						parent->_bf = subL->_bf = 0;
					}

				}
				else if (parent->_bf == 2 && cur->_bf == -1)//右左双旋
				{
					Node* subR = parent->_right;
					Node* subRL = subR->_left;
					int bf = subRL->_bf;
					RotateR(parent->_right);
					RotateL(parent);
					if (bf == -1)
					{
						parent->_bf = 0;
						subR->_bf = 1;
					}
					else if (bf == 1)
					{
						parent->_bf = -1;
						subR->_bf = 0;
					}
					else
					{
						parent->_bf = subR->_bf = 0;
					}
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
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
		if (pparent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
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

		subR->_bf = parent->_bf = 0;

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
		if (pparent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
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

		subL->_bf = parent->_bf = 0;
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	void Destroy(Node*& root)
	{
		if (root)
		{
			Destroy(root->_left);
			Destroy(root->_right);
			root = nullptr;
		}
	}
	void _Inorder(Node* root)
	{
		if (root)
		{
			_Inorder(root->_left);
			cout << root->_key <<" ";
			_Inorder(root->_right);
		}
	}
	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
	}
	bool IsBalanceTree(Node* root)
	{
		if (_root == nullptr)
			return true;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		int diff = rightHeight - leftHeight;
		if (diff != root->_bf)
		{
			cout << "结点平衡因子错误" << endl;
			return false;
		}
		if (diff > 1 || diff < -1)
		{
			return false;
		}
		else
		{
			return IsBalanceTree(root->_left) && IsBalanceTree(root->_right);
		}
	}
	Node* _root;
};
void TestAVLTree()
{
	AVLTree<int,int> tree;
	int arr[] = {16,3,7,11,9,26,18,14,15};
	for (auto& e : arr)
	{
		tree.Insert(e,e);
	}
	tree.Inorder();
}