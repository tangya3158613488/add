#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*1.��֤push_back��β��
  2.�ڿռ�����ķ�Χ�ڣ����Բ���������Ԫ��
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

//��֤����Ԫ���ڼ䣬vector���������
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

/*�Զ�������Ԫ�صĲ���
�Զ�������Ԫ���ڲ���ʱ��ʵ�ʲ�����Ƕ����һ�ݿ�����
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

/*��֤�Զ�������Ԫ��push_abck���Ǹ�Ԫ�صĿ���*/
void TestPushBack3()
{
	Date d(2020, 6, 7);
	vector<Date> v;
	v.push_back(d);
}

/*
�����Ҫ��߳�������Ч�ʣ������Ǽ����Ե�����£�����ʹ��C++11�е�emplace_back���о͵ع���
*/
void TestPushBack4()
{
	vector<Date> v;
	v.emplace_back(2020, 6, 1);
	cout << &v[0] << endl;
}

/*���������漰��Դ�������β��*/
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
	//������캯��
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		cout << "String(const String& s):" << this << endl;
	}

	//�ƶ����죬������������ֵ����
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
