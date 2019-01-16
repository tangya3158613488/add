#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void SetDate(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2019, 1, 15);
//	d1.Show();
//	d2.SetDate(2019, 1, 16);
//	d2.Show();
//	cout << sizeof(Date) << endl;
//	return 0;
//}

//class Person
//{
//public:
//	void ShowInfo()
//	{
//		cout << _name << " " << _age << " " << _sex << endl;
//	}
//	void PrintPersonInfo(const char* name,int age ,const char* sex)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_sex, sex);
//	}
//private:
//	char _name[20];
//	int _age;
//	char _sex[3];
//};
//int main()
//{
//	Person p;
//	p.PrintPersonInfo("Peter", 18, "男");
//	p.ShowInfo();
//	cout << sizeof(p) << endl;
//	return 0;
//}

//class Date
//{
//public:
//	//无参构造函数
//	Date()
//	{
//		_year = 2019;
//		_month = 1;
//		_day = 16;
//	}
//	//带参构造函数
//	/*Date(int year = 2019, int month = 1, int day = 15)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	return 0;
//}
//class String 
//{
//public:  
//	String(const char* str = "jack")  
//
//   { _str = (char*)malloc(strlen(str) + 1); 
//	strcpy(_str, str); 
//   }
//   ~String()   
//    { 
//	   cout << "~String()" << endl;   
//      free(_str); 
//     }
//private:   
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	//程序崩溃
//	String s1("hello");
//	String S2(s1);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2019, int month = 1, int day = 15)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._day;
//		_month = d._month;
//		_day = d._year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
//}

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date&d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	/*Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}*/
	//相等运算符重载
	bool operator==(const Date& d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	 Date d1(2019,1,16);
	 Date d2(2019,1,16);
	// Date d(2018, 12, 31);
	 cout << (d1 == d2) << endl;
	return 0;
}