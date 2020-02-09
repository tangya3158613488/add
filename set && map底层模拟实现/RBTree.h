#pragma once
#include<iostream>

using namespace std;
enum Color
{
	RED,
	BLACK
};
template<class ValueType>
struct RBTreeNode
{
	//ValueType,�����map����Ϊpair<K,V>�������set����Ϊk
	ValueType _Value;
	RBTreeNode<ValueType>* _left;
	RBTreeNode<ValueType>* _right;
	RBTreeNode<ValueType>* _parent;
	Color _color;

	RBTreeNode(const ValueType& v)
		: _Value(v)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(RED)
	{}
};

//������ĵ�����
template<class ValueType>
class RBTreeIterator
{
	typedef RBTreeNode<ValueType> Node;
	typedef RBTreeIterator<ValueType> self;
public:
	RBTreeIterator(Node* node)
		:_node(node)
	{}
	RBTreeIterator(const self& node)
		:_node(node._node)
	{}
	ValueType& operator*()
	{
		return _node->_Value;
	}
	ValueType* operator->()
	{
		return &_node->_Value;
	}
	self& operator==(const self& node)
	{
		return _node == node->_node;
	}
	bool operator!=(const self& node)
	{
		return _node != node._node;
	}
	self& operator++()
	{
		if (_node->_right)
		{
			Node* subR = _node->_right;
			while (subR->_left)
			{
				subR = subR->_left;
			}
			_node = subR;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	self& operator--()
	{
		if (_node->_left)
		{
			Node* subL = _node->_left;
			while (subL->_right)
			{
				subL = subL->_right;
			}
			_node = subL;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
private:
	Node* _node;//�������������ǽ���ָ��
};
template<class K,class V,class KeyOfValue>
class RBTree
{
	typedef V ValueType;
	typedef RBTreeNode<ValueType> Node;
public:
	typedef RBTreeIterator<ValueType> Iterator;
	RBTree()
		:_root(nullptr)
	{}
	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return Iterator(cur);
	}
	Iterator End()
	{
		return Iterator(nullptr);
	}

	pair<Iterator, bool> Insert(const ValueType& v)
	{
		if (nullptr == _root)
		{
			_root = new Node(v);
			_root->_color = BLACK;
			return make_pair(Iterator(_root), true);
		}
		KeyOfValue keyofvalue;
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (keyofvalue(v) < keyofvalue(cur->_Value))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (keyofvalue(v) > keyofvalue(cur->_Value))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(Iterator(cur), false);
			}
		}
		cur = new Node(v);
		if (keyofvalue(v) < keyofvalue(parent->_Value))
		{
			cur->_parent = parent;
			parent->_left = cur;
		}
		else
		{
			cur->_parent = parent;
			parent->_right = cur;
		}
		Node* newnode = cur;
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
						swap(cur, parent);
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
						swap(parent, cur);
					}
					RotateL(grandfather);
					grandfather->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
		}
		++_size;
		_root->_color = BLACK;
		return make_pair(Iterator(newnode), true);
	}
	Iterator Find(const K& key)
	{
		KeyOfValue keyofvalue;
		Node* cur = _root;
		while (cur)
		{
			if (keyofvalue(key) < keyofvalue(cur->_Value))
			{
				cur = cur->_left;
			}
			else if (keyofvalue(key) > keyofvalue(cur->_Value))
			{
				cur = cur->_right;
			}
			else
			{
				return Iterator(cur);
			}
		}
		return Iterator(nullptr);
	}
	size_t Size()const
	{
		return _size;
	}
	bool Empty()const
	{
		return 0 == _size;
	}
protected:
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
private:
	Node* _root;
	size_t _size;
};
