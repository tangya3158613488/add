#include<iostream>
using namespace std;

void _MergeSort(int* a, int* temp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	_MergeSort(a, temp, begin, mid);
	_MergeSort(a, temp, mid + 1, end);
	int index = begin;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
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
	while (begin1 <= end1)
	{
		temp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = a[begin2++];
	}
	index = begin;
	while (index <= end)
	{
		a[index++] = temp[index];
	}
}
void MergeSort(int* a, int n)
{
	int* temp = new int[n];
	_MergeSort(a, temp, 0, n - 1);
	delete[] temp;
}
int main()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
