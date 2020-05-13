#include<iostream>
using namespace std;

void SelectSort(int *a, int n)
{
	int flag = 0;//������ʶ��λ����Ŀǰ����Сֵ���±�
	int temp = 0;//ʼ�ձ�����Сֵ
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		flag = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < temp)
			{
				temp = a[j];
				flag = j;
			}
		}
		if (flag != i)
		{
			a[flag] = a[i];
			a[i] = temp;
		}
	}
}
int main()
{
	int a[] = { 5, 4, 9, 8, 7, 6, 0, 1, 3, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	SelectSort(a, len);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
