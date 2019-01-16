#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
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
//插入排序
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
	//PrintArray(a, n);
}
//希尔排序
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
//选择排序
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
//堆排序
void HeapSort(int* a, int n)
{
	//升序向下调整建大堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//选数
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	PrintArray(a, n);
}
//冒泡排序
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
//快速排序
//快速排序的优化
//1.三数取中法选key(针对直接有序的数组)
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin]>a[end])
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
int PartSort(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);
	int key = begin;//把第一个位置设成关键字
	while (begin < end)
	{
		//从后面选比关键字小的，如果关键字小于末尾的数，end往前走
		while (begin < end && a[key] <= a[end])
			--end;
		// 从前面选比关键字大的，如果关键字大于第一个数，begin就往后走
		while (begin < end && a[key] >= a[begin])
			++begin;
		//交换begin和end
		Swap(&a[begin], &a[end]);
	}
	//跳出循环时begin和end相遇，把第一个位置key的值换成此时begin的值
	Swap(&a[begin], &a[key]);
	return begin;
}
int PartSort3(int* a, int begin, int end)//前后指针版本
{
	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		//给定两个指针prev cur ,如果a[cur]>key cur继续往前走,当a[cur]<key时，
		//先++prev,若此时prev不等于cur，就交换a[prev]和a[cur]
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&key, &a[prev]);
	return prev;
}
int PartSort2(int* a, int begin, int end)//挖坑法
{
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && key <= a[end])
			--end;
		a[begin] = a[end];//此时begin=0;
		while (begin < end && key >= a[begin])
			++begin;
		a[end] = a[begin];
	}
	//此时begin和end相遇
	a[begin] = key;
	return begin;
}

int PartSort1(int* a,int begin,int end)//hoare版本
{
	int key = begin;//把第一个位置设成关键字
	while (begin < end)
	{
		//从后面选比关键字小的，如果关键字小于末尾的数，end往前走
		while (begin < end && a[key] <= a[end])
			--end;
		// 从前面选比关键字大的，如果关键字大于第一个数，begin就往后走
		while (begin < end && a[key] >= a[begin])
			++begin;
		//交换begin和end
		Swap(&a[begin], &a[end]);
	}
	//跳出循环时begin和end相遇，把第一个位置key的值换成此时begin的值
	Swap(&a[begin], &a[key]);
	return begin;
}
void QuickSort(int* a,int left,int right)
{
	//小区间优化
	if (left >= right)
		return;
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		//int div = PartSort1(a, left, right);
		//int div = PartSort1(a, left, right);
		int div = PartSort(a, left, right);
		//递归去div的左区间找新的关键字
		QuickSort(a, left, div - 1);
		//递归去div的右区间找新的关键字
		QuickSort(a, div + 1, right);
	}
}

//快速排序非递归
typedef int STDatatype;
typedef struct Stack
{
	STDatatype* _a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;

}

void StackPush(Stack* ps, STDatatype x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDatatype*)realloc(ps->_a, sizeof(STDatatype)*newcapacity);
		assert(ps->_a);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}
STDatatype StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartSort1(a, begin, end);
		//[div+1,end]
		if (div + 1 <end)//在此区间有元素就进栈
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
		//[begin,div-1]

		if (begin < div - 1)//在此区间有元素就进栈
		{
			StackPush(&st,div-1);
			StackPush(&st, begin);
		}
		
	}
}
//归并排序
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + ((end - begin) >> 1);
	//递归左区间
	_MergeSort(a, begin, mid, tmp);
	//递归右区间
	_MergeSort(a, mid + 1, end, tmp);
	//进行归并
	int index = begin;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	while (begin1 <= end1 && begin2 <= end2)//只要有一个区间走完了就停止循环
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//此时有一个区间走完
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//把tmp中的数据拷贝到原数组中
	memcpy(a ,tmp, sizeof(int)*(end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//计数排序
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	//for循环找到原数组中的最大值和最小值
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
		int range = max - min + 1;
		int* counta = (int*)malloc(sizeof(int)*range);
		memset(counta, 0, sizeof(int)*range);//将数组counta初始化为0
		//遍历原数组，统计每个数出现的次数
		for (int i = 0; i < n; i++)
		{
			counta[a[i] - min]++;
		}
		int index = 0;
		//遍历范围，对原数组排序
		for (int i = 0; i < range; i++)
		{
			while (counta[i]--)
			{
				a[index] = i + min;
				index++;
			}
		}
}
void TestSort()
{
	//将数组a进行升序排列
	int a[] = { 5, 3, 7, 8, 2, 1, 4, 9, 7, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	int begin = 0;
	int end = n - 1;
	/*InsertSort(a, n);
	ShellSort(a, n);
	SelectSort(a, n);
	HeapSort(a, n);
	BubbleSort(a, n);
	QuickSort(a, 0, n - 1);
	QuickSortNonR(a, 0, n - 1);*/
	//MergeSort(a, n);
	CountSort(a, n);
	PrintArray(a, n);
}

