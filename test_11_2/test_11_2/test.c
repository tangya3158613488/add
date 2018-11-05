#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int num = 10;
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//		
//	}
//	printf("二进制中1的个数=%d\n", count);
//	return 0;
//}

//两个int（32位）整数m和n的二进制表达式中，有多少个位（bit）不同
//方法一：
//#include<stdio.h>
//int cal_diff(int m, int n)
//{
//	int count = 0;
//	int i = 0; 
//	for (i = 0; i < 32; i++)
//	{//取出m和n对应位值的比较
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	printf("%d和%d中不同的位数:%d\n", m, n, cal_diff(m,n));
//	return 0;
//}
//

//方法二：
#include<stdio.h>
int cal_diff(int m, int n)
{
	//异或标记不同位
	int ret = m^n;
	int count = 0;
	while (ret)
	{
		ret = ret&(ret - 1);
		count++;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	printf("%d和%d中不同的位数:%d\n", m, n, cal_diff(m,n));
	return 0;
}