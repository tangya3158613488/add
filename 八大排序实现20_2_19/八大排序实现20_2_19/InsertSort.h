#pragma once;
#include<iostream>

using namespace std;

void Print(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//Ö±½Ó²åÈëÅÅÐòËã·¨
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
}
//Ï£¶ûÅÅÐò
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0 && a[end] > temp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = temp;
		}
	}
	/*for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			for (int j = i - gap; j >= 0; j -= gap)
			{
				if (a[j] > a[j + gap])
				{
					int temp = a[j];
					a[j] = a[j + gap];
					a[j + gap] = temp;
				}
			}
		}
	}*/
}
void TestInsertSort()
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, n);
	ShellSort(a, n);
	Print(a, n);
}
