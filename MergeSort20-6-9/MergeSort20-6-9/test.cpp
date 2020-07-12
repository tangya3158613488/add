#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end) //�˳�����
		return;
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid, tmp); // �ݹ��������
	_MergeSort(a, mid + 1, end, tmp); // �ݹ��Ұ�����

	//���ź��������������鲢������

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;

	while (begin1 <= end1 && begin2 <= end2)// ѭ����������һ�����������꣬����ֹ���������û�бȽ��������ֱ��һһ����ȥ
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
	
	//��tmp�е����ݿ�����ԭ������
	memcpy(a+begin, tmp+begin, sizeof(int)*(end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = new int[n];
	_MergeSort(a, 0, n - 1, tmp);
	delete[] tmp;
}
int main()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	MergeSort(a, len);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}