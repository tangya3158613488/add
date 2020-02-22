#include"common.h"

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child <= n - 1)
	{
		if (child + 1 < n && a[child] < a[child+1])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//ÅÅÉýÐò½¨´ó¶Ñ
void HeapSort(int* a,int n)
{
	for (int i = ((n - 1) - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	Print(a, n);
}
void TestHeapSort()
{
	int a[] = { 20, 17, 4, 16, 5, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
}