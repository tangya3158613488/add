#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	//带参构造函数
	/*Date(int year = 2019,int month = 1,int day = 15)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

   inline bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
   inline bool operator!=(const Date& d)const
   {
	   return !(*this == d);
   }
	inline bool operator>(const Date& d)const
	{
		return _year > d._year
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day);
	}
	inline bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;//复用
	}
	inline bool operator<(const Date& d)const
	{
		return !(*this >= d);//复用
	}
	inline bool operator<=(const Date& d)const
	{
		return !(*this > d);//复用
	}
	int GetMonthDay(int year, int month)
	{
		static int MonthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2
			&& year % 4 == 0 && year % 100 != 0
			|| year % 400 == 0)
			return 29;
		else
			return MonthArray[month];
	}
	//判断日期是否合法
	Date(int year = 2019, int month = 1 , int day = 16)
	{
		if (year >= 0
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}
	}
	//d1 + 10
	Date operator+(int day)
	{
		Date ret(*this);//拷贝构造ret
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			++ret._month;
			if (ret._month == 13)
			{
				++ret._year;
				ret._month = 1;
			}
		}
		//复用
		/*Date ret(*this);
		ret += day;*/
		return ret;
	}
	//d2 + 20
	Date operator-(int day)
	{
		Date ret(*this);
		ret._day -= day;
		while (ret._day <= 0)
		{
			if (ret._month == 1)
			{
				--ret._year;
				ret._month = 12;
			}
			--ret._month;
			ret._day += GetMonthDay(ret._year, ret._month);
		}
		//复用
		/*
		Date ret(*this);
		ret -= day;
		*/
		return ret;
	}
	//d3 += 26 运用进位思想
	Date& operator+=(int day)
	{
		//if (day < 0)
			//return *this -= (-day);
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	//d3 -= 50
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			if (_month == 1)
			{
				--_year;
				_month = 12;
			}
			--_month;
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	Date& operator++()// ++d 前置++
	{
		*this += 1;
		return *this;
	}
	Date& operator--()//--d 前置--
	{
		*this -= 1;
		return *this;
	}
	Date operator++(int)//++d 后置++
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	Date operator--(int)//--d 后置--
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}
	// d3 - d2
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min != max)
		{
			++day;
			++min;
		}
		return day*flag;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test1()
{
	Date d1(2019, 1, 15);
	Date d2(2019, 1, 16);
	cout << (d1 == d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
}
void Test2()
{
	Date d1(2019, 3, 28);
	d1.Print();

	Date d2 = d1 + 10;
	d2.Print();

	Date d3 = d2 - 20;
	d3.Print();

	d3 += 40;
	d3.Print();

	d3 -= 50;
	d3.Print();

	int d4 = d3 - d2;
	cout << d4 << endl;

	(++d3).Print();
	(d3++).Print();

	(--d1).Print();
	(d1--).Print();
	

}
int main()
{
	/*Date d(2019, 1, 16);
	d.Print();
	Date d2(d);
	d2.Print();*/
	//Test1();
	Test2();
	return 0;
}