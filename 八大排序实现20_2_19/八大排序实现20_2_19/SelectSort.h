#include"common.h"
void SelectSort(int* a,int n)
{
	int begin = 0;
	int end = n - 1;
	int max = 0; 
	int min = 0;
	while (begin < end)
	{
		min = begin;
		max = begin;
		for (int i = begin; i <= end; i++)
		{
			//找到每一轮的最大值和最小值
			if (a[min] > a[i])
			{
				min = i;
			}
			if (a[max] < a[i])
			{
				max = i;
			}
		}
		//将每一轮的最大值和最后一个元素交换，最小值和第一个元素交换，最后一个元素和第一个元素是在区间[begin,end]
		if (a[begin] != a[min])
		{
			Swap(&a[begin], &a[min]);
		}
		if (max == begin)
		{
			max = min;//如果首元素是最大的，则需要把max = min,此处的min对应的a[min]为最大值，在后面即在执行下一步Swap(&a[end], &a[max])相当于自己和自己交换即不改变相应位置的值。
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
	Print(a, n);
}
void TestSelectSort()
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	
}