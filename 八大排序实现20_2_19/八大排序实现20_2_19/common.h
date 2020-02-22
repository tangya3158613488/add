#pragma once;
#include<iostream>
using std::cout;
using std::endl;
void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int cur = i;
		int temp = a[cur + 1];
		while (cur >= 0)
		{
			if (a[cur] > temp)
			{
				a[cur + 1] = a[cur];
				a[cur] = temp;
				--cur;
			}
			else
			{
				break;
			}
		}
	}
	//Print(a, n);
}