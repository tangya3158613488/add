#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
void TestSet()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.insert(2);
	cout << s.size() << endl;
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	int arr[] = { 1, 2, 3, 4, 5, 2, 4, 6 };
	set<int> s2(arr, arr + sizeof(arr) / sizeof(int));
	cout << s2.size() << endl;
	for (auto& e : s2)
		cout << e << " ";
	cout << endl;
}
void TestMap()
{
	multimap<string, string> m;
	m.insert(make_pair("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("李逵", "铁牛"));
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	cout << m.count("李逵") << endl;
}
int main()
{
	TestSet();
	//TestMap();
	return 0;
}