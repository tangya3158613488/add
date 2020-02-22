#include"common.h"

void _MergeSort(int* a,int begin,int end,int* temp)
{
	if (begin >= end)
		return;
	if ((end - begin + 1) < 10)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	int mid = begin + ((end - begin) >> 1);
	//递归到左区间
	_MergeSort(a, begin, mid, temp);
	//递归到右区间
	_MergeSort(a, mid + 1, end, temp);
	//进行归并
	int index = begin;
	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[index++] = a[begin1++];
		}
		else
		{
			temp[index++] = a[begin2++];
		}
	}
	//右区间走完了
	while (begin1 <= end1)
	{
		temp[index++] = a[begin1++];
	}
	//左区间走完了
	while (begin2 <= end2)
	{
		temp[index++] = a[begin2++];
	}
	//将temp中的数据拷贝到原数组中
	memcpy(a, temp, sizeof(int)*(end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* temp = new int[n];
	_MergeSort(a, 0, n - 1, temp);
	delete[] temp;
}
void TestMergeSort()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 25, 13, 27, 100, 97, 58 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);
	Print(a, n);
}