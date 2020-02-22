#include"common.h"
#include<stack>

//快速排序常见的实现方式：hoare版本、挖坑法、前后指针法

//三数取中法(针对有序或接近有序的数组)
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}
//1.hoare版本
int PartSort1(int*a, int begin, int end)
{
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[key] <= a[end])
		{
			--end;
		}
		while (begin < end && a[key] >= a[begin])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	return begin;
}
//2.挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	mid = GetMidIndex(a, begin, end);
	if (mid != begin)
	{
		Swap(&a[mid], &a[begin]);
	}
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && key <= a[end])
		{
			--end;
		}
		a[begin] = a[end];
		while (begin < end && key >= a[begin])
		{
			++begin;
		}
		a[end] = a[begin];
	}
	//此时begin和end相遇
	a[begin] = key;
	return begin;
}
//3.前后指针法
int PartSort3(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	mid = GetMidIndex(a, begin, end);
	if (mid != begin)
	{
		Swap(&a[mid], &a[begin]);
	}
	int key = a[begin];
	int cur = begin + 1;
	int prev = begin;
	while (cur <= end)
	{
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[begin], &a[prev]);
	return prev;
}
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartSort1(a, left, right);
	QuickSort1(a, left, div - 1);
	QuickSort1(a, div + 1, right);
}
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartSort2(a, left, right);
	QuickSort2(a, left, div - 1);
	QuickSort2(a, div + 1, right);
}
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartSort3(a, left, right);
	QuickSort3(a, left, div - 1);
	QuickSort3(a, div + 1, right);
}
//优化：小区间优化+三数取中法
void QuickSort4(int* a, int left, int right)
{
	if (left >= right)
		return;
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		//int div = PartSort1(a, left, right);
		//int div = PartSort2(a, left, right);
		int div = PartSort3(a, left, right);
		//递归去div的左区间找新的关键字
		QuickSort4(a, left, div - 1);
		//递归去div的右区间找新的关键字
		QuickSort4(a, div + 1, right);
	}
}
//实现一个快速排序的非递归算法
void QuickSortNOR(int* a, int left, int right)
{
	std::stack<int> s;
	if (left < right)
	{
		s.push(left);
		s.push(right);
	}
	while (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();
		int div = PartSort3(a, begin, end);
		if ((end - begin + 1) < 10)//小区间优化直接插入排序
		{
			InsertSort(a + left, right - left + 1);
		}
		else
		{
			if (begin < div - 1)
			{
				s.push(begin);
				s.push(div - 1);
			}
			if (div + 1 < end)
			{
				s.push(div + 1);
				s.push(end);
			}
		}
	}
}
void TestQuickSort()
{
	int a[] = { 6, 1, 8, 2, 7, 9, 3, 4, 5, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	//QuickSort1(a, 0, n - 1);
	//QuickSort2(a, 0, n - 1);
	//QuickSort3(a, 0, n - 1);
	//QuickSort4(a, 0, n - 1);
	QuickSortNOR(a, 0, n - 1);
	Print(a, n);
}

