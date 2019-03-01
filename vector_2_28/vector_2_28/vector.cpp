#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	vector<int> v1;//int型的空vector
//	vector<int> v2(4, 10);//4个10
//	vector<int> v3(v2.begin(), v2.end());//迭代v2中的元素
//	vector<int> v4(v3);//拷贝v3
//	return 0;
//}
//void PrintVector(const vector<int>& v)
//{
//	//使用const迭代器进行遍历打印，注意const迭代器不能修改vector的内容
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
//	//使用push_back
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	//使用迭代器进行遍历打印
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//使用迭代器进行修改
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//	PrintVector(v);
//	//使用反向迭代器进行遍历打印
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
	
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);//使用find查找3所在位置的iterator
//	v.insert(pos, 10);//在pos位置之前插入10
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);//删除pos位置的元素
//    it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//vector的几种遍历方式
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//通过[]读写第0个位置
//	v[0] = 10;
//	cout << v[0] << endl;
//	//通过[i]的方式遍历vector
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
//	//C++11支持的新式遍历
//	for (auto x : v)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//  return 0;
//}
