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
//AVL�����Ķ���
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
		_root = nullptr;
	}

	bool Insert(const K& key,const V& value)
	{
		//�����Ϊ�գ������½��
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}
		//���ն����������������ҵ�Ҫ�����λ��
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
		//�����½��
		cur = new Node(key,value);
		if (key < parent->_key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		//����cur�ĸ��׽��
		cur->_parent = parent;

		//�����½���AVL����ƽ���Կ����⵽�ƻ�����ʱ��Ҫ����ƽ�����ӣ�������Ƿ��ƻ���AVL����ƽ����
		/*����ƽ������
		1)���cur���뵽parent����࣬��parent��ƽ������-1��
		2)���cur���뵽parent���Ҳ࣬��parent��ƽ������+1
		��ʱparent��ƽ�����ӿ����ǣ�0������1������2
		���parent��ƽ��������0��˵������֮ǰparent��ƽ������Ϊ����1������󱻵�����0����ʱ����AVL�������ʣ�����ɹ���
		���parent��ƽ������������1��˵������ǰparent��ƽ������һ��Ϊ0���������³�����1����ʱ��parentΪ�������ĸ߶����ӣ���Ҫ�������ϸ��¡�
		���parent��ƽ������Ϊ����2����parent��ƽ������Υ����ƽ���������ʣ���Ҫ���������ת�����Խ��͸߶ȡ�
		*/
		while (parent)
		{
			//���¸��׵�ƽ������
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			//���º��鸸�׵�ƽ��
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				//���ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//�����½���AVL����ƽ�����⵽�ƻ�����Ҫ����parentΪ������������ת����
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)//����˫��
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)//����˫��
				{
					RotateRL(parent);
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
	void RotateLR(Node* parent)
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
		subLR->_bf = 0;
	}
	void RotateRL(Node* parent)
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
		subRL->_bf = 0;
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

		subL->_bf = parent->_bf = 0;
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	void Height()
	{
		cout << _Height(_root) << endl;
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	bool _IsBalanceTree(Node* root)
	{
		if (_root == nullptr)
			return true;
 		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		if (abs(leftHeight - rightHeight) > 2 || (leftHeight - rightHeight) != root->_bf)
		{
			cout << " ƽ�����Ӵ���" << endl;
			return false;
		}
		return  _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
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
		cout << root->_key << " ";
		_Inorder(root->_right);
	}
	
	Node* _root;
};
void TestAVLTree()
{
	AVLTree<int,int> tree;
	int arr[] = { 26, 18, 14, 5, 3 };
	for (auto& e : arr)
	{
		tree.Insert(e,e);
	}
	tree.Inorder();
	tree.Height();
	tree.IsBalanceTree();
}