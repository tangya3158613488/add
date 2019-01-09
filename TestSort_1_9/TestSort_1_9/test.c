#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
int main()
{
	//将数组a进行升序排列
	int a[] = { 5, 3, 7, 8, 2, 1, 4, 9, 7, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	ShellSort(a, n);
	SelectSort(a, n);
	HeapSort(a, n);
	BubbleSort(a, n);
	return 0;
}