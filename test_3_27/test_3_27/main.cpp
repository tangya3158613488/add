#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//函数模板的特化
//template<class T>
//bool IsEqual(T& left,T& right)
//{
//	return left == right;
//}
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//	{
//		return true;
//	}
//	return false;
//}
//void Test() 
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//
//	cout << IsEqual(p1, p2) << endl;
//}
//int main()
//{
//	Test();
// 	return 0;
//}
//函数模板的全特化
//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<int,char>" << endl;
//	}
//private:
//	int _d1;
//	char _d2;
//};
//void Test()
//{
//	Data<char, int> d1;
//	Data<int, char> d2;
//}
//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<class T1>
//将第二个参数特化为char
//class Data<T1, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,char>" << endl;
//	}
//private:
//	T1 _d1;
//	char _d2;
//};
//
//
//template<typename T1, typename T2>
////两个参数特化为指针类型
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*,T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
////两个参数特化为引用类型
//template<typename T1, typename T2>
//class Data<T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&,T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//void Test()
//{
//	Data<double, char> d1;//调用特化的char版本
//	Data<int, int> d2;//调用基础的模板
//	Data<int*, char*> d3;//调用特化的指针版本
//	Data<int&, int&> d4(2,4);//嗲用特化的引用版本
//}
//int main()
//{
//	Test();
//	return 0;
//}
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	memcpy(dst, src, sizeof(T)*size);
//}
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	for (size_t i = 0; i < size; ++i)
//	{
//		dst[i] = src[i];
//	}
//}
//int main()
//{
//	string strarr1[3] = { "111", "222", "333" };
//	string strarr2[3];
//	Copy(strarr2, strarr1, 3);
//	return 0;
//}
//
//bool IsPODType(const char* strType)
//{
//	const char* arrType[] = { "int", "char", "short", "long", "long long", "float", "double", "long double" };
//	for (size_t i = 0; i < sizeof(arrType)/sizeof(arrType[0]); ++i)
//	{
//		if (0 == strcmp(strType, arrType[i]))
//			return true;
//	}
//	return false;
//}
//template<class T>
//void Copy(T* dst, const T* src, size_t size, bool IsPODType)
//{
//	if (IsPODType(typeid(T).name()))
//	{
//		memcpy(dst, src, sizeof(T)*size);
//	}
//	else
//	{
//		for (size_t i = 0; i < size; ++i)
//			dst[i] = src[i];
//	}
//}
////代表内置类型
//struct TrueType
//{
//	static bool Get()
//	{
//		return true;
//	}
//};
////代表自定义类型
//struct FalseType
//{
//	static bool Get()
//	{
//		return false;
//	}
//};
//template<class T>
//struct TypeTraits
//{
//	typedef FalseType IsPODType;
//};
//template<>
//struct TypeTraits<char> 
//{
//	typedef TrueType IsPODType; 
//};
//
//template<> 
//struct TypeTraits<short>
//{
//	typedef TrueType IsPODType;
//};
//
//template<> struct TypeTraits<int>
//{
//	typedef TrueType IsPODType;
//};
//
//template<> struct TypeTraits<long>
//{
//	typedef TrueType IsPODType;
//};
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	if (TypeTraits<T>::IsPODType::Get())
//		memcpy(dst, src, sizeof(T)*size);
//	else 
//	{
//		for (size_t i = 0; i < size; ++i)
//			dst[i] = src[i];
//	}
//}
//
//int main()
//{
//	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int a2[10]; 
//	Copy(a2, a1, 10);
//	string s1[] = { "1111", "2222", "3333", "4444" };
//	string s2[4];    
//	Copy(s2, s1, 4);
//	return 0; 
//}
#include"a.h" 
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}