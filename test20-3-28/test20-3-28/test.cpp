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
	decltype(++a) b = a;//��ʱbΪa�����ã�++a�Ľ��Ϊһ����ֵ
	decltype(a++) b = a;//��ʱa++�Ľ��Ϊһ����ֵ
	b = 20;
	cout << a << "," << b << endl;
	return 0;
}