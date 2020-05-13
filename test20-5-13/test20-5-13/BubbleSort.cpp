#include<iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
int main()
{
	int a[] = { 36, 25, 48, 12, 25, 65, 43, 57 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}