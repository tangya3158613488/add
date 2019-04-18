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
//map�ֵ䷭��
void TestMap1()
{
	std::map<std::string, std::string> m1;
	m1.insert(std::make_pair("banan","�㽶"));
	m1.insert(std::make_pair("apple", "ƻ��"));
	m1.insert(std::make_pair("waterme", "ˮ����"));
	m1.insert(std::make_pair("strawberry", "��ݮ"));
	std::map<std::string,std::string>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
//map����ͳ�Ƹ���
void TestMap2()
{
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
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
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
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
//map��Ԫ�ط���
void TestMap4()
{
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
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
	dict.insert(std::make_pair("left", "���"));
	dict.insert(std::make_pair("left", "ʣ��"));
	dict["left"] = "ʣ��";
	dict["string"] = "�ַ���";
	dict["set"] = "����";
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