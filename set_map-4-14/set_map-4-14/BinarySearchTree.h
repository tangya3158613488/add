#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
//������������ģ��ʵ��
#include<iostream>
using std::cout;
using std::endl;
template<class T>
struct BSTNode
{
	BSTNode(const T& key = T())
    	: _left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
	
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _key;
};
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		: _root(nullptr)
	{}
	
	~BSTree()
	{
		Destroy(_root);
	}
	//��������
	BSTree(const BSTree<T>& tree)
	{
		_root = Copy(tree._root);
	}
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* tmp = new Node;
		tmp->_left = Copy(root->_left);

		tmp->_right = Copy(root->_right);
		return tmp;
	}
	BSTree<T>& operator=(const BSTree<T>& tree)
	{
		if (this != &tree)
		{
			Destroy(this->_root);
			this->_root = Copy(tree._root);
		}
		return *this;
	}
	bool Insert(const T& key)
	{
		//�����Ϊ�գ�ֱ�Ӵ���һ���½����в���
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		//����Ҫ�����λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;//Ԫ���������Ѿ����ڣ��������²���
			}
		}
		//����Ԫ��
		cur = new Node(key);
		if (key < parent->_key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}
	Node* Find(const T& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
			{
				return cur;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		return nullptr;
	}
	bool Erase(const T& key)
	{
		//�����Ϊ�գ�ɾ��ʧ��
		if (_root == nullptr)
		{
			return false;
		}
		//����key�����е�λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key == cur->_key)
			{
				break;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		
		//�����������������key�������У��޷�ɾ��
		if (cur == nullptr)
		{
			return false;
		}
		//����������ҵ���key������ɾ�����,Ҫ�����������
		//1.�ý��ֻ���Һ���
		//2.�ý��ֻ������
		//3.�ý����������������
		if (cur->_left == nullptr)
		{
			//���1��
			//ֻ�и����͸����Һ��ӣ���ʱҪɾ���Ľ�����������ĸ�
			if (cur == _root)
			{
				_root = cur->_right;
			}
			else
			{
				//��ý�㲻�����ĸ�
				if (cur == parent->_left)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
			}
		}
		//���2��
		else if (cur->_right == nullptr)
		{
			if (cur == _root)
			{
				_root = cur->_left;
			}
			else
			{
				if (cur == parent->_right)
				{
					parent->_right = cur->_left;
				}
				else
				{
					parent->_left = cur->_left;
				}
			}

		}
		else
		{
			//��ǰ������Һ��Ӷ����ڣ�ֱ��ɾ������ɾ������������������һ�������㣬���������������е�����㣬�������������Ҳ�Ľ�㣬������������������С�Ľ�㣬������������С�Ľ�㡣�滻����ҵ��󣬽��������е�ֵ������ɾ����㣬ת����ɾ�������㡣
				if (cur->_left != nullptr || cur->_right != nullptr)
				{
					//������������С�Ľ���滻��ɾ���Ľ��
					Node* repalce = cur->_right;
					parent = cur;
					while (repalce->_left)
					{
						parent = repalce;
						repalce = repalce->_left;
					}
					cur->_key = repalce->_key;
					if (repalce == parent->_left)
					{
						parent->_left = repalce->_right;
					}
					else
					{
						parent->_right = repalce->_right;
					}
					delete repalce;
					repalce = nullptr;
				}
				return true;
		}
		return false;
	}
	void Inorder()
	{
		_Inorder(_root);
	}

private:
	void _Inorder(Node* root)
	{
		if (root)
		{
			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}
	}
	void Destroy(Node*& root)
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
void Test()
{
	BSTree<int> BST1;
	BST1.Insert(5);
	BST1.Insert(3);
	BST1.Insert(4);
	BST1.Insert(1);
	BST1.Insert(7);
	BST1.Insert(8);
	BST1.Insert(2);
	BST1.Insert(6);
	BST1.Insert(0);
	BST1.Insert(9);
	BST1.Inorder();
	cout << endl;
	BST1.Find(10);
	BST1.Erase(7);
	BST1.Inorder();
	/*BSTree<int> BST2(BST1);
	BST2.Insert(5);
	BST2.Insert(6);
	BST2.Insert(3);
	BST2.Inorder();
	BSTree<int>BST3 = BST2;
	cout << endl;
	BST3.Inorder();*/
}