#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	vector<int> v1;//int�͵Ŀ�vector
//	vector<int> v2(4, 10);//4��10
//	vector<int> v3(v2.begin(), v2.end());//����v2�е�Ԫ��
//	vector<int> v4(v3);//����v3
//	return 0;
//}
//void PrintVector(const vector<int>& v)
//{
//	//ʹ��const���������б�����ӡ��ע��const�����������޸�vector������
//	vector<int>::const_iterator it = v.cbegin();
//	while (it != v.cend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//int main()
//{
//	//ʹ��push_back
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	//ʹ�õ��������б�����ӡ
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//ʹ�õ����������޸�
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//	PrintVector(v);
//	//ʹ�÷�����������б�����ӡ
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//		{
//			sz = foo.capacity();
//			std::cout << "capacity changed:" << sz << '\n';
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a)/sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	v.pop_back();
//	v.pop_back();
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
	
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);//ʹ��find����3����λ�õ�iterator
//	v.insert(pos, 10);//��posλ��֮ǰ����10
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);//ɾ��posλ�õ�Ԫ��
//    it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//vector�ļ��ֱ�����ʽ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//ͨ��[]��д��0��λ��
//	v[0] = 10;
//	cout << v[0] << endl;
//	//ͨ��[i]�ķ�ʽ����vector
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	/*vector<int> swapv;
//	swapv.swap(v);
//	cout << "v.data:";
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	cout << "swapv data:";
//	for (size_t i = 0; i < swapv.size(); ++i)
//	{
//		cout << swapv[i] << " ";
//	}
//	cout << endl;*/
//	//C++11֧�ֵ���ʽ����
//	for (auto x : v)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//  return 0;
//}
