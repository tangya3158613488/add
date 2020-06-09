#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
	//lowΪ��1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��, midΪ��1�����������1��Ԫ��
	int i = low, j = mid + 1, k = 0;  //mid+1Ϊ�������1��Ԫ�أ�jָ���1��Ԫ��
	int *temp = new int[high - low + 1]; //temp�����ݴ�ϲ�����������
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) //��С���ȴ���temp��
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)//���Ƚ���֮������������ʣ�࣬��ֱ�Ӹ��Ƶ�t������
		temp[k++] = arr[i++];
	while (j <= high)//������
		temp[k++] = arr[j++];
	for (i = low, k = 0; i <= high; i++, k++)//���ź���Ĵ��arr��low��high������
		arr[i] = temp[k];
	delete[] temp;//�ͷ��ڴ棬����ָ��������飬������delete []
}
void MergeSort(int a[], int low, int high) 
{
	if (low >= high) 
		return;// ��ֹ�ݹ������
	int mid = low + (high - low) / 2;  // ȡ���м�Ԫ��
	MergeSort(a, low, mid);  // �����ߵݹ�
	MergeSort(a, mid + 1, high);  // ���Ұ�ߵݹ�
	if (a[mid] <= a[mid + 1]) 
		return; // ���ⲻ��Ҫ�Ĺ鲢
	Merge(a, low, mid, high);  // ���˺ϲ�
}

int main()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 5, 4, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	MergeSort(a, 0, len - 1);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}