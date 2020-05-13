//#include<iostream>
//using namespace std;
//
//void InsertSort(int* a, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int temp = a[i];
//		int j;
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (a[j] > temp)
//			{
//				a[j + 1] = a[j];
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[j + 1] = temp;
//	}
//}
//int main()
//{
//	int a[] = { 38, 65, 97, 76, 13, 27, 49 };
//	int n = sizeof(a) / sizeof(a[0]);
//	InsertSort(a, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}
