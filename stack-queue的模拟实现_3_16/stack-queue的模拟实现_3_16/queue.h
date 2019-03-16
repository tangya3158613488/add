#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<list>
#include<deque>
using namespace std;
template<class T, class Container = deque<T>>
class Queue
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_front();
	}
	const T& Back()
	{
		return _con.back();
	}
	const T& Front()
	{
		return _con.front();
	}
	size_t Size()const
	{
		return _con.size();
	}
	bool Empty()const
	{
		return _con.empty();
	}
private:
	Container _con;
};
void TestQueue()
{
	Queue<int, deque<int>> q1;
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	cout << q.Size() << endl;
	cout << q.Front() << endl;
}