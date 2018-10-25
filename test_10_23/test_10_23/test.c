#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int count_one_bits(unsigned int value)
{
	int i = 0;
	int count = 0;

	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
			count++;
	}
	return count;
}
int main()
{
	int num = -1;
	
	int count= count_one_bits(num);
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}
#include<stdio.h>
int main()
{
	int arr[32];
	int m = 0, i = 0, count = 0;
	printf("请输入一个十进制:\n");
	scanf("%d", &m);
	for (i = 0; m != 0; i++)
	{
		arr[i] = m % 2;
		m = m/ 2;
		count = i + 1;
	}
	for (; count < 32; count++)
	{
		arr[count] = 0;
	}
	printf("转换为二进制后奇数位为:\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("转换为二进制后偶数位为:\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int n = 2534;
	Print(n);
	return 0;
}
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int m = a^b;
	int count = 0;
	while (m > 0)
	{
		m = m&(m - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}