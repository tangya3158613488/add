#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
	//low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
	int i = low, j = mid + 1, k = 0;  //mid+1为右区间第1个元素，j指向第1个元素
	int *temp = new int[high - low + 1]; //temp数组暂存合并的有序序列
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) //较小的先存入temp中
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)//若比较完之后，右区间仍有剩余，则直接复制到t数组中
		temp[k++] = arr[i++];
	while (j <= high)//左区间
		temp[k++] = arr[j++];
	for (i = low, k = 0; i <= high; i++, k++)//将排好序的存回arr中low到high这区间
		arr[i] = temp[k];
	delete[] temp;//释放内存，由于指向的是数组，必须用delete []
}
void MergeSort(int a[], int low, int high) 
{
	if (low >= high) 
		return;// 终止递归的条件
	int mid = low + (high - low) / 2;  // 取得中间元素
	MergeSort(a, low, mid);  // 对左半边递归
	MergeSort(a, mid + 1, high);  // 对右半边递归
	if (a[mid] <= a[mid + 1]) 
		return; // 避免不必要的归并
	Merge(a, low, mid, high);  // 单趟合并
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