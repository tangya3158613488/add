#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<list>
#include<algorithm>
#include"list.h"
//using std::cout;
//using std::endl;
//������������ӡ����
//void Print_List(const std::list<int>& l)
//{
//	std::list<int>::const_iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
////list�����ӿڵĲ���
//void Test_list1()
//{
//	std::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	for (auto e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//Print_List(l);
//	//�޸ĵ������е�����
//	/*std::list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		*it = 10;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;*/
//	//���������
//	std::list<int>::reverse_iterator rit = l.rbegin();
//	while (rit != l.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//void Test_list2()
//{
//	std::list<int> l;
//	l.push_back(1);
//	l.push_back(3);
//	l.push_back(5);
//	l.pop_back();
//	l.push_front(0);
//	Print_List(l);
//	l.pop_front();
//	Print_List(l);
//}
//void Test_list3()
//{
//	std::list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	Print_List(l);
//	std::list<int>::iterator it = std::find(l.begin(), l.end(), 3);
//	if (it != l.end())
//	{
//		l.insert(it, 20);
//	}
//	Print_List(l);
//	it = std::find(l.begin(), l.end(), 3);
//	l.remove(3);
//	l.remove(20);
//	Print_List(l);
//	//erase���µ�����ʧЧ������ɾ���ܱ�2��������������취�������·�ʽ��
//	it = l.begin();
//	while (it != l.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = l.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//	Print_List(l);
//
//}
int main()
{
	//Test_list1();
	//Test_list2();
	//Test_list3();
	TestList1();
	return 0;
}