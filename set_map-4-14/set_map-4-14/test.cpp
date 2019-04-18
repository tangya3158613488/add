#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<map>
#include<string>
using std::cout;
using std::endl;

void TestSet()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	std::set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	s.insert(10);
	s.erase(8);
	auto it = s.rbegin();
	while (it != s.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	s.clear();
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
//map×Öµä·­Òë
void TestMap1()
{
	std::map<std::string, std::string> m1;
	m1.insert(std::make_pair("banan","Ïã½¶"));
	m1.insert(std::make_pair("apple", "Æ»¹û"));
	m1.insert(std::make_pair("waterme", "Ë®ÃÛÌÒ"));
	m1.insert(std::make_pair("strawberry", "²İİ®"));
	std::map<std::string,std::string>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
//map¿ÉÒÔÍ³¼Æ¸öÊı
void TestMap2()
{
	std::string strs[] = { "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "²İİ®", "²İİ®", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "Æ»¹û", "Æ»¹û" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		std::map<std::string, int>::iterator it = countmap.find(e);
		if (it != countmap.end())
		{
			it->second++;
		}
		else
		{
			countmap.insert(make_pair(e, 1));
		}
	}
	std::map<std::string, int>::iterator it = countmap.begin();
	while (it != countmap.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
void TestMap3()
{
	std::string strs[] = { "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "²İİ®", "²İİ®", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "Æ»¹û", "Æ»¹û" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
		//auto ret = countmap.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	
	//std::map<std::string, int>::iterator it = countmap.begin();
	auto it = countmap.begin();
	while (it != countmap.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
//mapµÄÔªËØ·ÃÎÊ
void TestMap4()
{
	std::string strs[] = { "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "²İİ®", "²İİ®", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "Æ»¹û", "Æ»¹û" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		countmap[e]++;
	}
	for (const auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	std::map<std::string, std::string> dict;
	dict.insert(std::make_pair("left", "×ó±ß"));
	dict.insert(std::make_pair("left", "Ê£Óà"));
	dict["left"] = "Ê£Óà";
	dict["string"] = "×Ö·û´®";
	dict["set"] = "¼¯ºÏ";
	for (const auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
#include"BinarySearchTree.h"
int main()
{
	//TestSet();
	//TestMap1();
	//TestMap2();
	//TestMap3();
	//TestMap4();
	 TestBSTree();
	return 0;
}