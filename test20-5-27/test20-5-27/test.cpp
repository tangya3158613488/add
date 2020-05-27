#define _CRT_SECURE_NO_WARNINGS 1
//对单链表进行排序
#include<iostream>
#define MAXSIZE 1024
#define LENGTH 8
using namespace std;

//使用归并排序
typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;

void Merge(SqList SR, SqList& TR, int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{
		if (SR.r[i] <= SR.r[j])
		{
			TR.r[k] = SR.r[i++];
		}
		else
		{
			TR.r[k] = SR.r[j++];
		}
	}
	while (i <= m)
	{
		TR.r[k++] = SR.r[i++];
	}
	while (j <= n)
	{
		TR.r[k++] = SR.r[j++];
	}
}

void _MergeSort(SqList SR, SqList& TR1, int s, int t)
{
	int m;
	SqList TR2;
	if (s == t)
	{
		TR1.r[s] = SR.r[t];
	}
	else
	{
		m = (s + t) / 2;
		_MergeSort(SR, TR2, s, m);
		_MergeSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}
void MergeSort(SqList& L)
{
	_MergeSort(L, L, 0, L.length - 1);
}

int main()
{
	SqList L = { { 45, 48, 24, 12, 0, 1, 99, 57 }, LENGTH };
	MergeSort(L);
	for (int i = 0; i < L.length; i++)
	{
		cout << L.r[i] << " ";
	}
	cout << endl;
	return 0;
}