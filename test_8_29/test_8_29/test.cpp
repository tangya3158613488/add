#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main()
//{
//	char arr[10] = { 0 };
//	memset(arr, '1', sizeof(arr));
//	cout << sizeof(arr) << endl;
//	cout << sizeof(arr[0]) << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}
#include<iostream>
using namespace std;

void test1(int arr[])
{
	cout << sizeof(arr) << endl;
}
void test2(char ch[])
{
	cout << sizeof(ch) << endl;
}

int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	cout << sizeof(arr) << endl;
	cout << sizeof(ch) << endl;
	test1(arr);
	test2(ch);
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	cout << ret << endl;
	cout << i << endl;
	int a = 0, b = 2, c = 3, d = 4;
	//int j = a++ && ++b && d++;
	int k = a++ || ++b || d++;
	//cout << j << " " << k << " " << endl;
	cout << "a= " << a << " " << "b= " << b << " " << "c= " << c << " " << "d= " << d << endl;
	char c2 = 3;
	cout << sizeof(c2) << endl;
	cout << sizeof(!c2) << endl;

	return 0;
}