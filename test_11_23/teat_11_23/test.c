#define _CRT_SECURE_NO_WARNINGS 1
//1. дһ�������ж�һ�����ǲ�������
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
			count++;//ͳ�ƴ�100~200֮�������ĸ���
		}
		printf("%d ", i);
	}
	printf("\ncount=%d", count);
	return 0;
}
//2.дһ�������ж�ĳһ���ǲ�������
#include<stdio.h>
int is_leap_year(year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�ж�year�����������
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
	printf("������һ�����:>");
	scanf("%d", &year);
	if (1 == is_leap_year)
	{
		printf("%d������\n");
	}
	else
	{
		printf("%d��������\n");
	}
	return 0;
}
// 3. дһ��������ʵ��һ��������������Ķ��ֲ���
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
	int k = 7;//��������7
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Binary_search(arr, k, 0, sz - 1);
	if (ret == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ���\n");
	}
	return 0;
}
//4. дһ��������ÿ����һ������������ͻὫnum��ֵ����1
include<stdio.h>
void Inc(int *p)
{
	(*p)++;
}
int main()
{
	int num = 0;
	//���ú�����ʹ��numÿ������1
	Inc(&num);
	printf("%d\n", num);
	return 0;
}
