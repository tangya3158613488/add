#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end) //退出条件
		return;
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid, tmp); // 递归左半数组
	_MergeSort(a, mid + 1, end, tmp); // 递归右半数组

	//将排好序的两部分数组归并（排序）

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;

	while (begin1 <= end1 && begin2 <= end2)// 循环条件：任一个数组排序完，则终止条件，最后将没有比较完的数组直接一一拷过去
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
	
	//将tmp中的数据拷贝到原数组中
	memcpy(a+begin, tmp+begin, sizeof(int)*(end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = new int[n];
	_MergeSort(a, 0, n - 1, tmp);
	delete[] tmp;
}
int main()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	MergeSort(a, len);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}