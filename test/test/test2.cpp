#include<iostream>
using namespace std;
int MonthDay(int year, int month, int day)
{
	int DayArray[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	if (year > 0 && ((year % 4 == 0 && year % 100 != 0)
		|| year % 400 == 0)){//�ж��Ƿ�������
		if (month > 2)
			return DayArray[month - 1] + 1 + day;//�����������һ��
		else
			return DayArray[month - 1] + day;
	}
	else
		return DayArray[month - 1] + day;
}
int main()
{
	int _year, _month, _day;
	while (cin >> _year >> _month >> _day)//������һ��oj�⣬����������ֹһ�������ʹ����Ҫѭ�������㲻ͬ�Ĳ�������
	{
		cout << MonthDay(_year, _month, _day) << endl;
	}
	return 0;
}
