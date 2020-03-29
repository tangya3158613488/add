//#include<iostream>
//#include<sstream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//	stringstream ss;
//	string s;
//	vector<int> data;
//	while (cin >> s)
//	{
//		ss << s;
//		int num;
//		while (ss >> num)
//		{
//			data.push_back(num);
//		}
//	}
//	for (int i = 0; i < data.size(); i++)
//	{
//		cout << data[i] << " ";
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	decltype(++a) b = a;//此时b为a的引用，++a的结果为一个左值
	decltype(a++) b = a;//此时a++的结果为一个右值
	b = 20;
	cout << a << "," << b << endl;
	return 0;
}