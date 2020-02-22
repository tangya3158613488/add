#include"common.h"

void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int flag = 0;
		for (int i = 0; i < end - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
		--end;
	}
	Print(a, n);
}
void TestBubbleSort()
{
	int a[] = { 15, 6, 56, 24, 9, 12, 55 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
}