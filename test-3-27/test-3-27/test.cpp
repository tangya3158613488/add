//中序打印二叉搜索树
#include<iostream>
using std::cout;
using std::endl;

template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& key = T())
	:_left(nullptr)
	,_right(nullptr)
	,_key(key)
	{}
	BSTreeNode<T>* _left;
	BSTreeNode<T>* _right;
	T _key;
};
template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	~BSTree()
	{
		Destroy(_root);
	}
	bool Insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key < cur->_key)
				cur = cur->_left;
			else if (key > cur->_key)
				cur = cur->_right;
			else
				return false;
		}
		cur = new Node(key);
		if (key < parent->_key)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}
	void PrintInorderBSTree()
	{
		InorderBSTree(_root);
	}
private:
	void InorderBSTree(Node* root)
	{
		if (root)
		{
			InorderBSTree(root->_left);
			cout << root->_key << " ";
			InorderBSTree(root->_right);
		}
	}
	void Destroy(Node*& root)
	{
		if (root)
		{
			Destroy(root->_left);
			Destroy(root->_left);
			root = nullptr;
		}
	}
	Node* _root;
};
void Test()
{
	BSTree<int> bst;
	bst.Insert(5);
	bst.Insert(5); 
	/*bst.Insert(4);
	bst.Insert(8);
	bst.Insert(1);
	bst.Insert(9);
	bst.Insert(0);*/
	bst.PrintInorderBSTree();
}
int main()
{
	Test();
	return 0;
}
//测试用例
//输入数据：不插入数据   预期结果：程序崩溃
//输入数据：插入几个数据不同的数据   预期结果：按升序打印出数据
//输入数据：插入几个数据，其中有相同的数据  预期结果：相同的数据只打印一个
//输入数据：插入一些其他类型的字符    预期结果：程序报错
//输入数据：插入只有左孩子/右孩子的数据  预期结果：程序正常打印
//输入数据：无限的插入数据，压力测试。  
