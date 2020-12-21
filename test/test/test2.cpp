#include<iostream>
using namespace std;
int MonthDay(int year, int month, int day)
{
	int DayArray[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	if (year > 0 && ((year % 4 == 0 && year % 100 != 0)
		|| year % 400 == 0)){//判断是否是闰年
		if (month > 2)
			return DayArray[month - 1] + 1 + day;//如果是闰年多加一天
		else
			return DayArray[month - 1] + day;
	}
	else
		return DayArray[month - 1] + day;
}
int main()
{
	int _year, _month, _day;
	while (cin >> _year >> _month >> _day)//本题是一道oj题，测试用例不止一个，因此使用需要循环来满足不同的测试用例
	{
		cout << MonthDay(_year, _month, _day) << endl;
	}
	return 0;
}
