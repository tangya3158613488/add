#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
//#include<algorithm>
using std::cout;
using std::endl;
namespace TY
{
	template<class T>
	struct __ListNode
	{
		__ListNode<T>* _next;
		__ListNode<T>* _prev;
		T _data;
		//创建结点
		__ListNode(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};
	//创建迭代器
	//typedef __Listiterator<T,T&,T*> iterator;
	//typedef __Listiterator<T,const T&,const T*> const_iterator;
	template<class T,class Ref,class Ptr>
	struct __Listiterator
	{
		typedef __ListNode<T> Node;
		typedef __Listiterator<T, Ref, Ptr> Self;
		Node* _node;
		__Listiterator()//无参构造迭代器
			:_node(nullptr)
		{}
		__Listiterator(Node* node)//带参构造迭代器
			:_node(node)
		{}
		//迭代器有两种实现方式：
		//1.原生态指针，如vectot
		//2.将原生态指针进行封装，因迭代器的使用形式与指针完全相同，
		//因此，在自定义的类中必须实现以下方法：
		// 1)指针可以解引用，迭代器的类中必须重载operator*()
		//2)指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
		//3)指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
		//至于operator--()/operator--(int)释放需要重载，
		//根据具体的结构来抉择双向链表可以向前移动，所以需要重载，如果是forward_list就不需要重载
		//4)迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=() 
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator==(const Self& self)
		{
			return _node == self._node;
		}
		bool operator!=(const Self& self)
		{
			return _node != self._node;
		}
	};
	template<class T>
	class List
	{
		typedef __ListNode<T> Node;
	public:
		typedef __Listiterator<T, T&, T*> iterator;
		typedef __Listiterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator cbegin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator cend()const
		{
			return const_iterator(_head);
		}
		List()//构造函数
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		List(const List<T>& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			List<T> tmp(l.cbegin(), l.cend());
			this->Swap(tmp);
		}
		List<T>& operator=(const List<T>& l)
		{
			if (this != &l)
			{
				List<T> tmp(l);
				this->Swap(tmp);
			}
			return *this;
		}
		~List()
		{
			Clear();
			delete _head;
			_head = nullptr;
		}
		void PushBack(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		void PopBack()
		{
			if (_head->_next == _head)
			{
				return;
			}
			Node* tail = _head->_prev;
			Node* prev = tail->_prev;
			prev->_next = _head;
			_head->_prev = prev;
			delete tail;
		}
		void PushFront(const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = _head->_next;
			_head->_next = newnode;
			newnode->_prev = _head;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void PopFront()
		{
			Node* cur = _head->_next;
			_head->_next = cur->_next;
			cur->_next->_prev = _head;
			delete cur;
		}
		iterator Insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator Erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return iterator(next);
		}
		void Swap(List<T>& l)
		{
			swap(_head, l._head);
		}
		void Clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		size_t size()const
		{
			size_t count = 0;
			Node* cur = _head->_next;
			while (cur != _head)
			{
				++count;
				cur = cur->_next;
			}
			return count;
		}
		bool Empty()const
		{
			return _head->_next = _head;
		}
		T& Front()
		{
			return _head->_next->_data;
		}
		const T& Front()const
		{
			return _head->_next->_data;
		}
		T& Back()
		{
			return _head->_prev->_data;
		}
		const T& Back()const
		{
			return _head->_prev->_data;
		}
	private:
		Node* _head;
	};
}
void TestList1()
{
	TY::List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.PopBack();
	//TY::List<int>::iterator it = std::find(l.begin(), l.end(), 3);
   // it = l.begin();
	TY::List<int>::iterator it = l.begin();
	l.Insert(it, 30);
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	l.PushFront(10);
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	l.PopFront();
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//cout << l.size() << endl;
	////cout << l.Empty() << endl;
	//cout << l.Front() << endl;
	//cout << l.Back() << endl;

}