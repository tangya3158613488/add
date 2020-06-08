#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*1.验证push_back是尾插
  2.在空间允许的范围内，可以插入任意多个元素
*/
void TestPushBack1()
{
	vector<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(i);

	for (auto e : v)
		cout << e << endl;
	cout << endl;
}

//验证插入元素期间，vector会进行扩容
void TestPushBack2()
{
	vector<int> v;
	size_t sz = v.capacity();
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << sz << endl;
		}
	}
}

/*自定义类型元素的插入
自定义类型元素在插入时，实际插入的是对象的一份拷贝。
*/
class Date
{
public:
	Date(int year = 2020, int month = 6, int day = 8)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

/*验证自定义类型元素push_abck的是该元素的拷贝*/
void TestPushBack3()
{
	Date d(2020, 6, 7);
	vector<Date> v;
	v.push_back(d);
}

/*
如果想要提高程序运行效率，不考虑兼容性的情况下，可以使用C++11中的emplace_back进行就地构造
*/
void TestPushBack4()
{
	vector<Date> v;
	v.emplace_back(2020, 6, 1);
	cout << &v[0] << endl;
}

/*对于类中涉及资源管理进行尾插*/
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		cout << "String(const char*):" << this << endl;
	}
	//深拷贝构造函数
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		cout << "String(const String& s):" << this << endl;
	}

	//移动构造，参数必须用右值引用
	String(String&& s)
		: _str(s._str)
	{
		s._str = nullptr;
		cout << "String(String&& s):" << this << endl;
	}
	~String()
	{
		if (nullptr != _str)
		{
			delete[] _str;
			_str = nullptr;
		}
		cout << "~String():" << this << endl;
	}
private:
	char* _str;
};

void TestPushBack5()
{
	//String s("hello");
	vector<String> v;
	v.push_back(String("hello"));
}

int main()
{
	//TestPushBack1();
	//TestPushBack2();
	//TestPushBack3();
	//TestPushBack4();
	TestPushBack5();
	return 0;
}
