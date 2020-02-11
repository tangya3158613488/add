#pragma once
#include"HashTable.h"
#include"common.h"
template<class K, class V,class HashFunc = HashFunc<K>>
class UnorderedMap
{
	typedef pair<K, V> ValueType;
	
	struct KeyOfValue
	{
		const K& operator()(const ValueType& kv)
		{
			return kv.first;
		}
	};
public:
	typedef typename HashTable<K, ValueType, KeyOfValue, HashFunc>::iterator iterator;
	UnorderedMap()
		: _ht()
	{}
	//iterator
	iterator begin()
	{
		return _ht.Begin();
	}
	iterator end()
	{
		return _ht.End();
	}

	//capacity
	size_t size()const
	{
		return _ht.Size();
	}
	bool empty()const
	{
		return _ht.Empty();
	}

	//Acess
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}

	iterator find(const K& key)
	{
		return _ht.Find(key);
	}
	size_t count(const K& key)
	{
		return _ht.Count();
	}

	//modify
	pair<iterator, bool> insert(const ValueType& kv)
	{
		return _ht.Insert(kv);
	}
private:
	HashTable<K,ValueType, KeyOfValue,HashFunc> _ht;
};

void TestUnorderedMap()
{
	UnorderedMap<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(15, 15));
	m.find(5);
	
	UnorderedMap<int, int>::iterator it = m.begin();
	
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;
	UnorderedMap<string, string> dict;
	dict.insert(make_pair("string", "×Ö·û´®"));
	dict.insert(make_pair("left", "×ó±ß"));
	dict["left"] = "Ê£Óà";

	UnorderedMap<string, string>::iterator it2 = dict.begin();

	while (it2 != dict.end())
	{
		cout << it2->first << " ";
		++it2;
	}
	cout << endl;
}