#pragma once
#include<iostream>

using std::cout;
using std::endl;

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_left(nullptr)
		, _right(nullptr)
		, _data(data)
	{}
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	~BSTree()
	{
		Destroy(_root);
	}
	//拷贝构造
	BSTree(const BSTree<T>& tree)
	{
		_root = Copy(tree._root);
	}
	Node* Copy(Node* root)
	{
		if (nullptr == root)
			return nullptr;
		Node* tmp = new Node;
		tmp->_data = root->_data;
		tmp->_left = Copy(root->_left);
		tmp->_right = Copy(root->_right);
		return tmp;
	}
	//赋值重载
	BSTree& operator=(const BSTree& tree)
	{
		if (this != &tree)
		{
			Destroy(this->_root);
			this->_root = Copy(tree._root);
		}
		return *this;
	}
	Node* Find(const T& data)
	{
		Node* cur = _root;
		while (cur)
		{
			if (data == cur->_data)
				return cur;
			else if (data < cur->_data)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		//如果树为空，直接插入
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data > cur->_data)
				cur = cur->_right;
			else
				return false;
		}
		//插入元素
		cur = new Node(data);
		if (data < parent->_data)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}
	bool Erase(const T& data)
	{
		//如果树为空，删除失败
		if (nullptr == _root)
			return false;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data < cur->_data)
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
		if (nullptr == cur->_left)
		{
			if (cur == _root)
				_root = cur->_right;
			else
			{
				if (cur == parent->_left)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
		}
		else if (nullptr == cur->_right)
		{
			if (cur == _root)
				_root = cur->_left;
			else
			{
				if (cur == parent->_left)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
		}
		else
		{
			//当前结点左右孩子都存在，直接删除不好删，可以在其子树中找一个替代结点，
			//比如找其左子树中的最大结点，即左子树中最右侧的结点，或者找其右子树中的最小结点。
			//替换结点找到后，将替代结点中的值交给待删结点，从而转换成删除替代结点，这样不会破坏树的结构。
			if (cur->_left != nullptr || cur->_right != nullptr)
			{
				Node* replace = cur->_right;
				parent = cur;
				while (replace->_left)
				{
					parent = replace;
					replace = replace->_left;
				}
				cur->_data = replace->_data;
				if (replace == parent->_left)
					parent->_left = replace->_right;
				else
					parent->_right = replace->_right;
				delete replace;
				replace = nullptr;
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
			cout << root->_data << " ";
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

void TestBSTree()
{
	BSTree<int> bt1;
	bt1.Insert(5);
	bt1.Insert(3);
	bt1.Insert(4);
	bt1.Insert(1);
	bt1.Insert(7);
	bt1.Insert(8);
	bt1.Insert(2);
	bt1.Insert(6);
	bt1.Insert(0);
	bt1.Insert(9);
	bt1.Inorder();
	cout << endl;

	bt1.Find(9);
	bt1.Find(10);
	bt1.Inorder();
	cout << endl;
	BSTree<int> copy(bt1);
	copy.Inorder();
	cout << endl;

	BSTree<int> bt2;
	bt2 = bt1;
	copy.Inorder();
	cout << endl;
	bt2.Inorder();
	cout << endl;

	bt2.Erase(8);
	bt2.Inorder();
	cout << endl;
	bt2.Erase(5);
	bt2.Inorder();
}
