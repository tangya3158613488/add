#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void sort(int *arr, int sz)
{
	int i = 0;
	int j = sz - 1;
	for (i = 0; i != j; i++)
	{
		if (arr[i] % 2 != 0)
			continue;
		else
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			j--;
			i--;
		}
	}
}
int main()
{
	int arr[] = { 1, 9, 5, 6, 4, 3, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

#include<stdio.h>
int search(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	while ((x < row) && (y >= 0))
	{
		if (k>arr[x][y])
		{
			x++;
		}
		else if (k == arr[x][y])
		{
			return 1;
		}
		else
		{
			y--;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 5;
	int ret = 0;
	ret = search(arr, key, 3, 3);
	if (1 == key)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}