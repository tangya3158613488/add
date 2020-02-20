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
			//�ҵ�ÿһ�ֵ����ֵ����Сֵ
			if (a[min] > a[i])
			{
				min = i;
			}
			if (a[max] < a[i])
			{
				max = i;
			}
		}
		//��ÿһ�ֵ����ֵ�����һ��Ԫ�ؽ�������Сֵ�͵�һ��Ԫ�ؽ��������һ��Ԫ�غ͵�һ��Ԫ����������[begin,end]
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
	Print(a, n);
}
void TestSelectSort()
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	
}