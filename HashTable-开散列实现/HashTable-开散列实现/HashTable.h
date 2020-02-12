#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class V>
struct HashNode
{
	HashNode<V>* _next;
	V _value;

	HashNode(const V& v)
		: _next(nullptr)
		, _value(v)
	{}
};
//K：关键码类型。
//V：不同容器的V的类型不同，如果是unoredered_map，V代表一个键值对，如果是unordered_set，V为K
//KeyOfValue：因为V的类型不同，通过value取key的方式也就不同。
//HashFunc：哈希函数仿函数对象类型，哈希函数使用除留余数法，需要将key转换成整形数字才能取模。

//为了实现简单，在哈希表的迭代器类中需要用到HashTable本身，所以采用前置声明
template<class K,class V,class KeyOfValue,class HashFunc>
class HashTable;

template<class K, class V, class KeyOfValue,class HashFunc>
struct HTIterator
{
	typedef HashNode<V> Node;
	typedef HTIterator<K, V, KeyOfValue, HashFunc> Self;
	Node* _node;
	HashTable<K, V, KeyOfValue, HashFunc>* _ht;

	HTIterator(Node* node, HashTable<K, V, KeyOfValue, HashFunc>* ht)
		: _node(node)
		, _ht(ht)
	{}
	//因为哈希表在底层是单链表结构，所以哈希表的迭代器不需要实现--操作
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			KeyOfValue kov;
			size_t index = _ht->HashIndex(kov(_node->_value), _ht->_table.size());
			++index;
			while (index < _ht->_table.size())
			{
				if (_ht->_table[index])
				{
					_node = _ht->_table[index];
					break;
				}
				++index;
			}
			if (index == _ht->_table.size())
				_node = nullptr;
		}
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		++(*this);
		return temp;
	}

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &_node->_value;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node && _ht == s._ht;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};
template<class K,class V,class KeyOfValue,class HashFunc>
class HashTable
{
	typedef HashNode<V> Node;
	template<class K,class V,class KeyOfValue,class HashFunc>
	friend struct HTIterator;
public:
	typedef HTIterator<K, V, KeyOfValue, HashFunc> iterator;
	HashTable()
		: _size(0)
	{}
	~HashTable()
	{
		Clear();
	}
	KeyOfValue kov;
	iterator Begin()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			if (_table[i] != nullptr)
			{
				return iterator(_table[i], this);//this代表哈希表的指针
			}
		}
		return iterator(nullptr,this);
	}
	iterator End()
	{
		return iterator(nullptr, this);
	}

	pair<iterator, bool> Insert(const V& v)
	{
		CheckCapacity();
		size_t index = HashIndex(kov(v), _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_value) == kov(v))
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;
		++_size;
		return make_pair(iterator(newnode, this), true);
	}

	iterator Find(const K& key)
	{
		size_t index = HashIndex(key, _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_value) == key)
			{
				return iterator(cur,this);
			}
			cur = cur->_next;
		}
		return iterator(nullptr, this);
	}

	bool Erase(const K& key)
	{
		size_t index = HashIndex(key, _table.size());
		Node* prev = nullptr;
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_value) == key)
			{
				if (prev == nullptr)
					_table[index] = cur->_next;
				else
					prev->_next = cur->_next;
				--_size;
				delete cur;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}

	size_t Size()const
	{
		return _size;
	}
	void Clear()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			Node* cur = _table[i];
			while (cur)
			{
				_table[i] = cur->_next;
				delete cur;
				cur = _table[i];
			}
		}
		_size = 0;
	}
	bool Empty()const
	{
		return 0 == _size;
	}
	size_t Count(const K& key)
	{
		size_t index = HashIndex(key, _table.size());
		Node* cur = _table[i];
		while (cur)
		{
			if (kov(cur->_value) == key)
				break;
			cur = cur->_next;
		}
		size_t count = 0;
		while (cur)
		{
			if (kov(cur->_value) == key)
			{
				count++;
				cur = cur->_next;
			}
			else
				break;
		}
		return count;
	}
private:
	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			vector<Node*> _newtable;
			_newtable.resize(newsize,nullptr);
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];//将旧表结点插入到新表
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = HashIndex(kov(cur->_value), _newtable.size());
					//头插到新表
					cur->_next = _newtable[index];
					_newtable[index] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(_newtable);
		}
	}
	size_t HashIndex(const K& key, size_t size)
	{
		HashFunc hf;
		return hf(key) % size;
	}

private:
	vector<Node*> _table;
	size_t _size = 0;
};
