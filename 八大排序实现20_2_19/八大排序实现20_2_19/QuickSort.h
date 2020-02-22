#include"common.h"
#include<stack>

//�������򳣼���ʵ�ַ�ʽ��hoare�汾���ڿӷ���ǰ��ָ�뷨

//����ȡ�з�(��������ӽ����������)
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
//1.hoare�汾
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
//2.�ڿӷ�
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
	//��ʱbegin��end����
	a[begin] = key;
	return begin;
}
//3.ǰ��ָ�뷨
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
//�Ż���С�����Ż�+����ȡ�з�
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
		//�ݹ�ȥdiv�����������µĹؼ���
		QuickSort4(a, left, div - 1);
		//�ݹ�ȥdiv�����������µĹؼ���
		QuickSort4(a, div + 1, right);
	}
}
//ʵ��һ����������ķǵݹ��㷨
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
		if ((end - begin + 1) < 10)//С�����Ż�ֱ�Ӳ�������
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

