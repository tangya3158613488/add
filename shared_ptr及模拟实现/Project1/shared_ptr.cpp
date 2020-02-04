#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
using namespace std;
struct Date{
	int _year;
	int _month;
	int _day;
};
int main()
{
	shared_ptr<Date> sp;
	shared_ptr<Date> copy(sp);
	cout << "ref count: " << sp.use_count() << endl;
	cout << "ref count: " << copy.use_count() << endl;
	return 0;
}