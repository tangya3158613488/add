#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*int main()
{
	/*char str[] = { 'a', 'b', 'c', 'd' };
	for (size_t i = 0; i < 4; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	char *p = "abcdef";
	while (*p != '\0')
	{
		cout << *p++ << " ";
	}
	cout << endl;
	int a = 10;
	decltype(--a) b = a;
	b = 20;
	cout << a << "," << b << endl;
	return 0;
}*/


/*class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// 拷贝构造
	// String s(左值对象)
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}

	// 移动构造
	// String s(将亡值对象) 
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;

		swap(_str, s._str);
	}

	// s1 = s2
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}


	// 移动赋值
	// s1 = s2
	String& operator=(String&& s)
	{
		cout << "String& operator=(String&& s)" << endl;
		swap(_str, s._str);

		return *this;
	}

	~String()
	{
		if (_str) delete[] _str;
	}

	// s1 += s2  体现左值引用，传参和传值的位置减少拷贝，提高效率  
	String& operator+=(const String& s)
	{
		//this->Append(s.c_str());
		return *this;
	}

	// s1 + s2
	String operator+(const String& s)
	{
		String tmp(*this);
		//tmp.Append(s.c_str());
		return tmp;
	}

	const char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};

struct Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	String s1("hello");
	String s2("hello");

	//s1 += s2;
	//String ret = s1 + s2;
	String ret;
	ret = s1 + s2;

	vector<string> v;
	string str("world");
	v.push_back(str);
	//v.push_back(move(str));
	v.push_back("hello");

	v.emplace_back("hello");
	v.emplace_back(str);
	v.emplace_back(move(str));

	vector<Date> vd;
	Date d1(2019, 6, 25);
	vd.push_back(d1); // 左值
	vd.push_back(Date(2020, 2, 13)); // 右值
	//vd.push_back(2019, 6, 26);


	vd.emplace_back(Date(2020, 2, 15));
	vd.emplace_back(d1);
	//vd.emplace_back(2019, 6, 26);


	return 0;
}*/

//lambda表达式的运用
/*int main()
{
	int a = 0, b = 1;
	// 用尽可能多的方式写多个lambda表达式实现a b交换
	/*auto swap1 = [](int& x1, int& x2)
				{
					int x = x1;
					x1 = x2;
					x2 = x;
				};

	swap1(a, b);
	cout << a << endl;
	cout << b << endl;

	auto swap2 = [&a, &b]()
	{
		int x = a;
		a = b;
		b = x;
	};

	swap2();
	cout << a << endl;
	cout << b << endl;
	auto swap3 = [&]()
	{
		int x = a;
		a = b;
		b = x;
	};

	swap3();
	cout << a << endl;
	cout << b << endl;

	return 0;
}*/

//C++11通过forward函数实现完美转发
/*void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
void Fun(const int &x){ cout << "const lvalue ref" << endl; }
void Fun(const int &&x){ cout << "const rvalue ref" << endl; }
template<typename T>
void PerfectForward(T &&t)
{
	Fun(std::forward<T>(t)); 
}
int main()
{
	PerfectForward(10); // rvalue re
	int a;
	PerfectForward(a);			   // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref

	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref

	return 0;
}*/

//C++11中的线程库
//#include <thread>
//#include <mutex>
//
//void add(int* px, int n, mutex* pmtx)
//{
//	pmtx->lock();
//	for (int i = 0; i < n; ++i)
//	{
//		++(*px);
//	}
//	pmtx->unlock();
//}
//int main()
//{
//	int x = 0;
//	mutex mtx;
//	thread t1(add, &x, 1000000, &mtx);
//	thread t2(add, &x, 1000000, &mtx);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

#include <thread>
#include <mutex>
#include <atomic>

int main()
{
	int x = 0;
	std::mutex mtx;
	//atomic<int> x = 0;
	size_t n = 1000000;
	thread t1;
	thread t2;

	t1 = thread([&]()
	{
		unique_lock<mutex> lock(mtx);
		for (size_t i = 0; i < n; ++i)
		{
			++x;
		}

		/*for (size_t i = 0; i < n; ++i)
		{
			++x;
		}*/
	});

	t2 = thread([&]()
	{
		unique_lock<mutex> lock(mtx);
		for (size_t i = 0; i < n; ++i)
		{
			++x;
		}

		/*for (size_t i = 0; i < n; ++i)
		{
			++x;
		}*/
	});

	t1.join();
	t2.join();

	cout << x << endl;

	return 0;
}
//void foo()
//{
//	this_thread::sleep_for(std::chrono::seconds(1));
//}
//int main()
//{
//	thread t(foo);
//	cout << "before join, joinable=" << t.joinable() << std::endl;
//	t.join();
//	cout << "after join, joinable=" << t.joinable() << endl;
//	return 0;
//}