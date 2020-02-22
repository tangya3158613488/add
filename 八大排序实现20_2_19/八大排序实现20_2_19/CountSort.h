#include"common.h"

void CountSort(int* a,int n)
{
	int max = a[0];
	int min = a[0];
	//ѭ���ҵ�ԭ�����е����ֵ����Сֵ
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* counta = new int[range];
	memset(counta, 0, sizeof(int)*range);//��������counta�е�ÿ��Ԫ���ʼ��Ϊ0
	//����ԭ���飬ͳ��ÿ�������ֵĴ���
	for (int i = 0; i < n; i++)
	{
		counta[a[i] - min]++;
	}
	int index = 0;
	//������Χ
	for (int i = 0; i < range; i++)
	{
		while (counta[i]--)
		{
			a[index] = i + min;
			index++;
		}
	}
}
void TestCountSort()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 25, 13, 27, 100, 97, 58 };
	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	Print(a, n);
}