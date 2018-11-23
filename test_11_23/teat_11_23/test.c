#define _CRT_SECURE_NO_WARNINGS 1
//1. 写一个函数判断一个数是不是素数
#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
	int j = 0;
	for (j = 2; j <= sqrt(n); j++)
	{
		if (n%j == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		if (1 == is_prime(i))
		{
			count++;//统计从100~200之间素数的个数
		}
		printf("%d ", i);
	}
	printf("\ncount=%d", count);
	return 0;
}
//2.写一个函数判断某一年是不是闰年
#include<stdio.h>
int is_leap_year(year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//判断year是闰年的条件
	{
		return 1
	}
	else
	{
		return 0;
	}
}
int main()
{
	int year = 0;
	printf("请输入一个年份:>");
	scanf("%d", &year);
	if (1 == is_leap_year)
	{
		printf("%d是闰年\n");
	}
	else
	{
		printf("%d不是闰年\n");
	}
	return 0;
}
// 3. 写一个函数，实现一个整形有序数组的二分查找
#include<stdio.h>
int Binary_search(*arr, int k, int left, int right)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 7;//查找数字7
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Binary_search(arr, k, 0, sz - 1);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了\n");
	}
	return 0;
}
//4. 写一个函数，每调用一次这个函数，就会将num的值增加1
include<stdio.h>
void Inc(int *p)
{
	(*p)++;
}
int main()
{
	int num = 0;
	//调用函数，使得num每次增加1
	Inc(&num);
	printf("%d\n", num);
	return 0;
}
