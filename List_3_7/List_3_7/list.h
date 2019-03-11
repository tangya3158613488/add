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
		//�������
		__ListNode(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};
	//����������
	//typedef __Listiterator<T,T&,T*> iterator;
	//typedef __Listiterator<T,const T&,const T*> const_iterator;
	template<class T,class Ref,class Ptr>
	struct __Listiterator
	{
		typedef __ListNode<T> Node;
		typedef __Listiterator<T, Ref, Ptr> Self;
		Node* _node;
		__Listiterator()//�޲ι��������
			:_node(nullptr)
		{}
		__Listiterator(Node* node)//���ι��������
			:_node(node)
		{}
		//������������ʵ�ַ�ʽ��
		//1.ԭ��ָ̬�룬��vectot
		//2.��ԭ��ָ̬����з�װ�����������ʹ����ʽ��ָ����ȫ��ͬ��
		//��ˣ����Զ�������б���ʵ�����·�����
		// 1)ָ����Խ����ã������������б�������operator*()
		//2)ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
		//3)ָ�����++����ƶ������������б�������operator++()��operator++(int)
		//����operator--()/operator--(int)�ͷ���Ҫ���أ�
		//���ݾ���Ľṹ������˫�����������ǰ�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����
		//4)��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=() 
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
		List()//���캯��
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