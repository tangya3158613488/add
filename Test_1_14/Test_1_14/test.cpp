#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//�����ռ�Ķ����ʹ��
//namespace N1
//{
//	int a = 12;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int c = Add(2, 3);
//}
//namespace N2
//{
//	int b = 11;
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//	int d = Sub(5, 2);
//}
//using namespace N1;
//using namespace N2;
//int main()
//{
//	cout << N1::a << endl;
//	cout << N2::b << endl;
//	cout << N1::c << endl;
//	cout << N2::d << endl;
//	printf("%d\n", N1::a);
//	printf("%d\n", N1::c);
//	return 0;
//}
//ȱʡ����
//void TestFunc(int a = 10,int b = 20,int c = 30)
//{
//	cout << "a = "<<a<< endl;
//	cout << "b = " <<b<< endl;
//	cout << "c = " <<c<< endl;
//}
//int main()
//{
//	TestFunc(1,2,3);//����ʱ��ʹ��ָ����ʵ��
//	TestFunc(1);
//	//TestFunc();//û�д���ʱ��ʹ�ø�����Ĭ��ֵ
//	return 0;
//}

//����
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c ;
//}
//int main()
//{
//	int& ret = Add(2, 4);//��������ʱ���뿪�������������ջ�ϵĿռ��Ѿ���������ϵͳ
//	cout << "Add(2,4) is :" << ret << endl;
//	return 0;
//}
//��ֵ��������Ч�ʵıȽ�
//#include<time.h>
//struct A
//{
//	int a[10000];
//};
//void TestFunc1(A a)
//{}
//void TestFunc2(A& a)
//{}
//void TestRefAndValue()
//{
//	A a;
//	//��ָ����Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	//��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	cout << "TestFunc1(int*)-time: " << end1 - begin1 << endl;
//	cout << "TestFunc2(int&)-time: " << end2 - begin2 << endl;
//}
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndValue();
//	}
//	return 0;
//}

//ָ���������Ϊ����ֵ���͵����ܱȽ�
//#include<time.h>
//struct A
//{
//	int a[10000];
//};
//A a;
//A TestFunc1()
//{
//	return a;
//}
//A& TestFunc2()
//{
//	return a;
//}
//void TestRefAndValue()
//{
//	//��ָ����Ϊ��������
//		size_t begin1 = clock();
//		for (size_t i = 0; i < 10000; ++i)
//			TestFunc1();
//		size_t end1 = clock();
//	
//		//��������Ϊ��������
//		size_t begin2 = clock();
//		for (size_t i = 0; i < 10000; ++i)
//			TestFunc2();
//		size_t end2 = clock();
//		cout << "TestFunc1-time: " << end1 - begin1 << endl;
//		cout << "TestFunc2-time: " << end2 - begin2 << endl;
//}
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndValue();
//	}
//	return 0;
//}

void TestFunc(int a = 10)
{ 
	cout << "void TestFunc(int)" << endl; 
}

void TestFunc(int a) 
{ 
	cout << "void TestFunc(int)" << endl;
}
