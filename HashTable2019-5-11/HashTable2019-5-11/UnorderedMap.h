#pragma once
#include "HashTable.h"
#include<iostream>
using namespace std;
template<class K>
struct HashFunc
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

template<>
struct HashFunc<std::string>
{
	size_t operator()(const std::string& s)
	{
		size_t hash = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			hash = hash * 131 + s[i];
		}

		return hash;
	}
};

template<class K, class T, class HashFunc = HashFunc<K>>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const std::pair<K, T>& kv)
		{
			return kv.first;
		}
	};

public:
	typedef typename OPEN::HashTable<K, std::pair<K, T>, MapKeyOfValue, HashFunc>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	pair<iterator, bool> Insert(const std::pair<K, T>& kv)
	{
		return _ht.Insert(kv);
	}

	T& operator[](const K& key)
	{
		std::pair<iterator, bool> ret = _ht.Insert(make_pair(key, T()));
		return ret.first->second;
	}

private:
	OPEN::HashTable<K, std::pair<K, T>, MapKeyOfValue, HashFunc> _ht;
};
void TestUnorderedMap()
{
	UnorderedMap<int, int> m;
	m.Insert(std::make_pair(15, 15));
	m.Insert(std::make_pair(5, 5));
	m.Insert(std::make_pair(25, 25));

	for (size_t i = 0; i < 11; ++i)
	{
		m.Insert(std::make_pair(i, i));
	}
	m[35] = 15;
	UnorderedMap<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl << endl;

	//for (auto& e : m)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}
	//cout << endl << endl;


	UnorderedMap<std::string, std::string> dict;
	dict["sort"] = "≈≈–Ú";


	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}

}