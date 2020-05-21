#include<iostream>
using namespace std;
//给定一个含有n个元素的数组，其中只有一个元素出现奇数次，找出这个元素。
//int FindElementWithOddCount(int* a, int n)
//{
//	int s = a[0];
//	for (int i = 1; i < n; i++)
//	{
//		s ^= a[i];
//	}
//	return s;
//}
//int main()
//{
//	int arr[] = { 1, 2, 2, 3, 3, 4, 1 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	cout << FindElementWithOddCount(arr, len) << endl;
//	return 0;
//}

//引申：由n个元素组成的数组，n-2个数出现了偶数次，两个数出现了奇数次（这两个数不相等），如何使用O(1)的空间复杂度找出这个数

void FindElement(int* a, int n)
{
	int s = a[0];
	for (int i = 1; i < n; i++)
	{
		s ^= a[i];
	}
	int s1 = s;
	int s2 = s;
	int k = 0;
	while (!(s1 & 1))
	{
		s1 = s1 >> 1;
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if ((a[i] >> k) & 1)
		{
			s ^= a[i];
		}
	}
	int s3 = s^s2;
	cout << s << " " << s3 << endl;
}
int main()
{
	int arr[] = { 1, 2, 2, 3, 3, 4, 1, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	FindElement(arr, len);
	return 0;
}
