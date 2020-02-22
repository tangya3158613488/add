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
//��������
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
//ϣ������
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
//ѡ������
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
		if (max == begin)
		{
			max = min;//�����Ԫ�������ģ�����Ҫ��max = min,�˴���min��Ӧ��a[min]Ϊ���ֵ���ں��漴��ִ����һ��Swap(&a[end], &a[max])�൱���Լ����Լ����������ı���Ӧλ�õ�ֵ��
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
//������
void HeapSort(int* a, int n)
{
	//�������µ��������
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//ѡ��
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	PrintArray(a, n);
}
//ð������
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
//��������
//����������Ż�
//1.����ȡ�з�ѡkey(���ֱ�����������)
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
	int key = begin;//�ѵ�һ��λ����ɹؼ���
	while (begin < end)
	{
		//�Ӻ���ѡ�ȹؼ���С�ģ�����ؼ���С��ĩβ������end��ǰ��
		while (begin < end && a[key] <= a[end])
			--end;
		// ��ǰ��ѡ�ȹؼ��ִ�ģ�����ؼ��ִ��ڵ�һ������begin��������
		while (begin < end && a[key] >= a[begin])
			++begin;
		//����begin��end
		Swap(&a[begin], &a[end]);
	}
	//����ѭ��ʱbegin��end�������ѵ�һ��λ��key��ֵ���ɴ�ʱbegin��ֵ
	Swap(&a[begin], &a[key]);
	return begin;
}
int PartSort3(int* a, int begin, int end)//ǰ��ָ��汾
{
	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		//��������ָ��prev cur ,���a[cur]>key cur������ǰ��,��a[cur]<keyʱ��
		//��++prev,����ʱprev������cur���ͽ���a[prev]��a[cur]
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[begin], &a[prev]);
	return prev;
}
int PartSort2(int* a, int begin, int end)//�ڿӷ�
{
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && key <= a[end])
			--end;
		a[begin] = a[end];//��ʱbegin=0;
		while (begin < end && key >= a[begin])
			++begin;
		a[end] = a[begin];
	}
	//��ʱbegin��end����
	a[begin] = key;
	return begin;
}

int PartSort1(int* a,int begin,int end)//hoare�汾
{
	int key = begin;//�ѵ�һ��λ����ɹؼ���
	while (begin < end)
	{
		//�Ӻ���ѡ�ȹؼ���С�ģ�����ؼ���С��ĩβ������end��ǰ��
		while (begin < end && a[key] <= a[end])
			--end;
		// ��ǰ��ѡ�ȹؼ��ִ�ģ�����ؼ��ִ��ڵ�һ������begin��������
		while (begin < end && a[key] >= a[begin])
			++begin;
		//����begin��end
		Swap(&a[begin], &a[end]);
	}
	//����ѭ��ʱbegin��end�������ѵ�һ��λ��key��ֵ���ɴ�ʱbegin��ֵ
	Swap(&a[begin], &a[key]);
	return begin;
}
void QuickSort(int* a,int left,int right)
{
	//С�����Ż�
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
		//�ݹ�ȥdiv�����������µĹؼ���
		QuickSort(a, left, div - 1);
		//�ݹ�ȥdiv�����������µĹؼ���
		QuickSort(a, div + 1, right);
	}
}

//��������ǵݹ�
typedef int STDatatype;
typedef struct Stack
{
	STDatatype* _a;
	int _top;//ջ��
	int _capacity;//����
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
		if (div + 1 <end)//�ڴ�������Ԫ�ؾͽ�ջ
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
		//[begin,div-1]

		if (begin < div - 1)//�ڴ�������Ԫ�ؾͽ�ջ
		{
			StackPush(&st,div-1);
			StackPush(&st, begin);
		}
		
	}
}
//�鲢����
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + ((end - begin) >> 1);
	//�ݹ�������
	_MergeSort(a, begin, mid, tmp);
	//�ݹ�������
	_MergeSort(a, mid + 1, end, tmp);
	//���й鲢
	int index = begin;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	while (begin1 <= end1 && begin2 <= end2)//ֻҪ��һ�����������˾�ֹͣѭ��
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
	//��ʱ��һ����������
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//��tmp�е����ݿ�����ԭ������
	memcpy(a ,tmp, sizeof(int)*(end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//��������
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	//forѭ���ҵ�ԭ�����е����ֵ����Сֵ
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
		memset(counta, 0, sizeof(int)*range);//������counta��ʼ��Ϊ0
		//����ԭ���飬ͳ��ÿ�������ֵĴ���
		for (int i = 0; i < n; i++)
		{
			counta[a[i] - min]++;
		}
		int index = 0;
		//������Χ����ԭ��������
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
	//������a������������
	int a[] = { 5, 3, 7, 8, 2, 1, 4, 9, 7, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	int begin = 0;
	int end = n - 1;
	InsertSort(a, n);
	/*ShellSort(a, n);
	SelectSort(a, n);
	HeapSort(a, n);
	BubbleSort(a, n);
	QuickSort(a, 0, n - 1);
	QuickSortNonR(a, 0, n - 1);*/
	//MergeSort(a, n);
	//CountSort(a, n);
	//PrintArray(a, n);
}

