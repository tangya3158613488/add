#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void mul(int x)
{
	int i = 0, j = 0;
	for (i= 1; i <= x; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	mul(a);
	return 0;
}
#include<stdio.h>
void Swap(int *px, int *py)
{
	int tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	Sawp(&num1, &num2);
	printf("Swap::num1=%d num2=%d\n", num1, num2);
	return 0;
}

#include<stdio.h>
int leap_year(int year)
{
	if ((year % 4 == 0 && year / 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int year;
	int ret = 0;
	printf("请输入年份:");
	scanf("%d", &year);
	ret = leap_year(year);
	if (ret == 1)
	{
		printf("%d年是闰年\n", year);
	}
	else
	{
		printf("%d年非闰年\n", year);
	}
	return 0;
	
}
#include<stdio.h>
#include<windows.h>
int judge_num(int n)
{
	int i=0;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return -1;
		}
	}
	return 0;
}
int main()
{

	int num = 0;
	int result = 0;
	printf("请输入一个数字: ");
	scanf("%d", &num);
	result = judge_num(num);
	if (result == 0)
		printf("%d是素数\n", num);
	else
		printf("%d不是素数\n", num);
	return 0;
}