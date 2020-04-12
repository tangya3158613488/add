#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n = 6;
	int a[] = { 3, 7, 1, 4, 1, 2 };
	int b[] = { 3, 7, 3, 6, 3, 2 };
	int i = 0;
	int j = n - 1;
	while (a[i] == b[i])
	{
		++i;
	}
	while (a[j] == b[j])
	{
		--j;
	}
	int k = a[i] - b[i];
	++i;
	while (i <= j)
	{
		if (a[i] - b[i] == k)
			++i;
		else
			break;
	}
	if (i <= j)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}