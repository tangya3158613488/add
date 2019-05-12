#pragma once
#include<vector>
namespace CLOSE
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE,
	};
	template<class K,class V>
	struct HashNode
	{
		std::pair<K, V> _kv;
		State _state;
	};
	template<class K,class V>
	struct HashTable
	{
		typedef HashNode<K, V> HashNode;
	public:
		HashTable(size_t N = 10)
		{
			_table.resize(N);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				_table[i]._state = EMPTY;
			}
			_size = 0;
		}
		bool Insert(const std::pair<K, V>& kv)
		{
			//先检查哈希表底层空间是否充足
			CheckCapacity();
			size_t index = kv.first % _table.size();
			while (_table[index]._state == EXIST)
			{
				if (_table[index]._kv.first == kv.first)
				{
					return true;
				}
				//线性探测，解决哈希冲突
				++index;
				if (index == _table.size())
					index = 0;
			}
			_table[index]._kv = kv;
			_table[index]._state = EXIST;
			++_size;
			return true;
		}
		void CheckCapacity()
		{
			//荷载因子等于0.7就开始增容
			if (_table.size() == 0 || _size * 10 / _table.size() == 7)
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				HashTable<K, V> _newht(newsize);
				//将旧表中的数据重新在新表中算其所在的位置
				for (size_t i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXIST)
					{
						_newht.Insert(_table[i]._kv);
					}
				}
				_table.swap(_newht._table);
			}
		}
		HashNode* Find(const K& key)
		{
			size_t index = key % _table.size();
			while (_table[index]._state != EMPTY)
			{
				if (_table[index]._kv.first == key && _table[index]._state == EXIST)
				{
					return &_table[index];
				}
				++index;
				if (index == _table.size())
				{
					index = 0;
				}
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashNode* node = Find(key);
			if (node == nullptr)
			{
				return false;
			}
			else
			{
				node->_state = DELETE;
				--_size;
				return true;
			}
		}
	private:
		std::vector<HashNode> _table;
		size_t _size;//有效数据的个数
	};
	void TestHashTable()
	{
		HashTable<int, int> ht;
		ht.Insert(std::make_pair(1, 1));
		ht.Insert(std::make_pair(3, 3));
		ht.Insert(std::make_pair(5, 5));
		ht.Insert(std::make_pair(2, 2));
		ht.Insert(std::make_pair(3, 3));
		ht.Find(5);
		ht.Erase(3);
	}
}
namespace OPEN
{
	template<class V>
	struct HashNode
	{
		HashNode<V>* _next;
		V _value;
		HashNode(const V& v)
			: _value(v)
			, _next(nullptr)
		{}
	};
	template<class K, class V, class KeyOfValue, class HashFunc>
	class HashTable;

	template<class K, class V, class KeyOfValue, class HashFunc>
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

		V& operator*()
		{
			return _node->_value;
		}
		V* operator->()
		{
			return &_node->_value;
		}
		Self operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				//找下一个不为空的桶
				size_t i = _ht->HashIndex(KeyOfValue()(_node->_value), _ht->_table.size());
				++i;
				for (; i < _ht->_table.size(); ++i)
				{
					if (_ht->_table[i] != nullptr)
					{
						_node = _ht->_table[i];
						break;
					}
				}

				if (i == _ht->_table.size())
				{
					_node = nullptr;
				}
			}

			return *this;
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
		template<class K, class V, class KeyOfValue, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, V, KeyOfValue, HashFunc> iterator;
		HashTable()
			: _size(0)
		{}
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				if (_table[i] != nullptr)
				{
					return iterator(_table[i], this);
				}
			}
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}
		std::pair<iterator, bool> Insert(const V& v)
		{
			CheckCapacity();
			KeyOfValue kov;
			const K& key = kov(v);
			size_t index = HashIndex(key, _table.size());
			Node* cur = _table[index];
			while (cur)
			{
				if (kov(cur->_value) == kov(v))
					return make_pair(iterator(cur, this), false);
				cur = cur->_next;
			}
			//插入新元素，头插
			Node* newnode = new Node(v);
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_size;
			return make_pair(iterator(newnode, this), true);
		}
		void CheckCapacity()
		{
			//当荷载因子==1时扩容
			if (_size == _table.size())
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				std::vector<Node*> newtable;
				newtable.resize(newsize);
				for (size_t i = 0; i < _table.size(); ++i)
				{
					//遍历旧表，把旧表中的结点插入到新表中
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = HashIndex(KeyOfValue()(cur->_value),newsize);
						cur->_next = newtable[index];
						newtable[index] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newtable);
			}
		}
		size_t HashIndex(const K& key, size_t size)
		{
			HashFunc hf;
			return hf(key) % size;
		}
	private:
		std::vector<Node*> _table;//哈希表里存的是结点指针
		size_t _size;//有效数据的个数
	};
}
