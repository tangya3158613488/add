#include"common.h"
//Ö±½Ó²åÈëÅÅÐòËã·¨

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
	Print(a, n);
}
void TestInsertSort()
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, n);
	ShellSort(a, n);
	
}
