#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<functional>//greater算法的头文件
using namespace std;
class Date
{
public:
	Date(int year = 2019, int month = 3, int day = 16)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			   (_year == d._year && _month < d._month) ||
			   (_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			   (_year == d._year && _month > d._month) ||
			   (_year == d._year && _month > d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Less
{
public:
	bool operator()(const Date& left, const Date& right)
	{
		return left < right;
	}
};
class Greater
{
public:
	bool operator()(const Date& left, const Date& right)
	{
		return left > right;
	}
};
void TestPriorityQueue()
{
	//默认情况下创建的是大堆
	vector<int> v{ 1, 2, 5, 3, 6, 8, 9, 7 };
	priority_queue<int> pq1;
	for (auto& e : v)
		pq1.push(e);
	cout << pq1.top() << endl;
	//如果要创建小堆，将第三个模板参数换成greater比较方式
	priority_queue<int, vector<int>, greater<int>> pq2(v.begin(), v.end());
	cout << pq2.top() << endl;
	priority_queue<Date> q1;
	q1.push(Date(2019, 3, 12));
	q1.push(Date(2019, 3, 15));
	q1.push(Date(2019, 3, 14));
	cout << q1.top() << endl;
	//建小堆，需要用户提供>的重载
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2019, 3, 12));
	q2.push(Date(2019, 3, 15));
	q2.push(Date(2019, 3, 14));
	cout << q2.top() << endl;
	priority_queue<Date, vector<Date>, Greater> q3;
	q3.push(Date(2019, 11, 2));
	q3.push(Date(2019, 3, 18));
	q3.push(Date(2019, 2, 20));
	cout << q3.top() << endl;
}
int main()
{
	TestPriorityQueue();
	return 0;
}