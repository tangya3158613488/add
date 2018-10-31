#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
unsigned int reverse_bit(unsigned int value)
{
	unsigned int sum = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		sum += ((value >> i) & 1 )<< (31 - i);//取出最低位，左移到相应位置
	}
	return sum;
}
int main()
{
	unsigned int num = 25;
  printf("反转后:%u\n", reverse_bit(num));
  return 0;
}

#include<stdio.h>
int averge(int a, int b)
{
	int averge = 0;
	if (a > b)
	{
		b = ((a - b) / 2) + b;
		averge = b;
	}
	else
	{
		a = ((b - a) / 2) + a;
		averge = a;
	}
	return averge;
}
int main()
{
	int a = 0;
	int b = 0;
	//int averge = 0;
	scanf("%d%d", &a, &b);
	//averge = (a&b) + ((a^b) >> 1);
	printf("a和b的平均数为:%d\n", averge(a,b));
	return 0;
}

#include<stdio.h>
int main()
{
	int arr[] = { 1, 5, 5, 2, 7, 2, 8, 7, 9, 9, 8 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < sz; i++)
	{
		arr[0] = arr[0] ^ arr[i];//相同为0，相异为1
	}
	printf("这个只出现一次的数字为:%d\n", arr[0]);
	return 0;
}

