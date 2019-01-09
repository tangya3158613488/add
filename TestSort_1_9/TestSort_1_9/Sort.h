#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>

void PrintArray(int* a, int n)
{

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] >tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
	PrintArray(a, n);
}
//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i <= n - gap - 1; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	PrintArray(a, n);
}
//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int max = 0;
	int min = 0;
	int i = 0;
	while (begin < end)
	{
		min = begin;
		max = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			if (a[i] <= a[min])
			{
				min = i;
			}
		}
		if (a[begin] != a[min])
		{
			Swap(&a[begin], &a[min]);
		}
		if (a[begin] == a[max])
		{
			max = begin;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
	PrintArray(a, n);
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child <= n - 1)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
		if (a[child]>a[parent])
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
//∂—≈≈–Ú
void HeapSort(int* a, int n)
{
	//…˝–ÚœÚœ¬µ˜’˚Ω®¥Û∂—
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//—° ˝
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	PrintArray(a, n);
}
//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		int flag = 0;
		for (int i = 0; i <= end; i++)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
			--end;
		}
	}
	PrintArray(a, n);

}