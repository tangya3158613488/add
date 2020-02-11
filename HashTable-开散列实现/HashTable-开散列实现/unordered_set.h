#pragma once
#include"HashTable.h"
#include"common.h"
template<class K,class HashFunc = HashFunc<K>>
class UnorderSet
{
	typedef K ValueType;
	struct KeyOfValue
	{
		const K& operator()(const ValueType& v)
		{
			return v;
		}
	};
public:
	typedef typename HashTable<K, ValueType, KeyOfValue, HashFunc>::iterator iterator;
	pair<iterator, bool> insert(const ValueType& kv)
	{
		return _ht.Insert(kv);
	}
	iterator find(const K& key)
	{
		return _ht.Find(key);
	}
	size_t count(const K& key)
	{
		return _ht.Count();
	}
	iterator begin()
	{
		return _ht.Begin();
	}
	iterator end()
	{
		return _ht.End();
	}
private:
		HashTable<K, ValueType, KeyOfValue, HashFunc> _ht;
};
void TestUnorderedSet()
{
	UnorderSet<int> s;
	s.insert(2);
	s.insert(6);
	s.insert(4);
	s.insert(14);
	s.insert(16);
	s.find(2);
	UnorderSet<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}