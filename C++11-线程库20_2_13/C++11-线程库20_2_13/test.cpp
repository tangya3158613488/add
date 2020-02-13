#define _CRT_SECURE_NO_WARNINGS 1
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <windows.h>

using namespace std;

mutex data_mutex;
condition_variable data_var;
bool flag = true;
int i = 0;

void printA()
{
	while (i)
	{
		Sleep(1000);
		if (flag)
		{
			cout << "thread: " << this_thread::get_id() << "   printf: " << i << endl;
			i += 1;
			flag = false;
		}

	}
}

void printB()
{
	while (i)
	{
		if (!flag)
		{
			cout << "thread: " << this_thread::get_id() << "   printf: " << i << endl;
			i += 1;
			flag = true;
		}
	}
}
int main()
{
	thread t1(printA);
	thread t2(printB);

	t1.join();
	t2.join();
	return 0;
}