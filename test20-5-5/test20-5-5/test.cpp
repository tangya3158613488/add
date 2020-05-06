//#include<stdio.h>
//int my(const int a)
//{
//	static int count = a;
//	return count + a;
//}
//int main()
//{
//	printf("%d\n%d\n", my(4), my(5));
//	return 0;
//}
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date()
	{}
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin,Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}