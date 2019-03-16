#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
template<class T, class Container = vector<T>, class Compare = less<T>>
class PriorityQueue
{
public:
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) >> 1;
		while (child > 0)
		{
			Compare com;
			if (com(_con[parent] , _con[child]))
			{
				swap(_con[parent], _con[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
	void AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child < _con.size())
		{
			Compare com;
			if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
			{
				++child;
			}
			if (com(_con[parent], _con[child]))
			{
				swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void Push(const T& x)
	{
		_con.push_back(x);
		AdjustUp(_con.size() - 1);
	}
	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		AdjustDown(0);
	}
	const T& Top()
	{
		return _con[0];
	}
	size_t Size()
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};
void TestPriorityQueue()
{
	PriorityQueue<int, vector<int>, less<int>> pq;
	pq.Push(5);
	pq.Push(6);
	pq.Push(1);
	pq.Push(2);
	pq.Push(9);
	pq.Push(10);

	while (!pq.Empty())
	{
		cout << pq.Top() << " ";
		pq.Pop();
	}
	cout << endl;
}