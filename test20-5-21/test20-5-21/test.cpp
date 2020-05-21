#include<iostream>
using namespace std;
//����һ������n��Ԫ�ص����飬����ֻ��һ��Ԫ�س��������Σ��ҳ����Ԫ�ء�
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

//���꣺��n��Ԫ����ɵ����飬n-2����������ż���Σ������������������Σ�������������ȣ������ʹ��O(1)�Ŀռ临�Ӷ��ҳ������

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
