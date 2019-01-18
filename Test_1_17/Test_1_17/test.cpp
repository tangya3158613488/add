#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class A1
//{
//public:
//	void f1()
//	{}
//private:
//	int _a;
//	//类中仅有成员函数
//};
//class A2
//{
//public:
//	void f2()
//	{}
//};
////类中什么也没有（空类）
//class A3
//{};
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	return 0;
//}

//struct s1
//{
//	char a;
//	int i;
//	char c;
//};
//int main()
//{
//	cout << sizeof(s1) << endl;
//	return 0;
//}


//int globalval = 1;
//static int staticglobalval = 1;
//void Test()
//{
//	static int staticval = 1;
//	int locaval = 1;
//	int num[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pchar = "abcd";
//	cout << sizeof(char2) << endl;
//	cout << strlen(char2) << endl;
//	cout << strlen(pchar) << endl;
//	int* ptr1 = (int*)malloc(sizeof(int)* 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	cout << sizeof(ptr1) << endl;
//	cout << sizeof(ptr3) << endl;
//
//	free(ptr1);
//	free(ptr3);
//}
//int main()
//{
//	Test();
//	return 0;
//}


class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test():" << this << endl;
	}
	void Test2()
	{

		//申请单个Test类型的空间
		Test* p1 = (Test*)malloc(sizeof(Test));
		free(p1);
		//申请10个Test类型的空间
		Test* p2 = (Test*)malloc(sizeof(Test)* 10);
		free(p2);
	}

	void Test3()
	{
		//申请单个Test类型的空间
		Test* p1 = new Test;
		delete p1;
		//申请10个Test类型的空间
		Test* p2 = new Test[10];
		delete[] p2;
	}

	~Test()
	{
		cout << "Test():" << this << endl;
	}
private:
	int _data;
};
int main()
{
	Test;
	return 0;
}