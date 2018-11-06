#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//指针试题
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);
//	int *ptr2 = (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//

//编写函数：
//unsigned int reverse_bit(unsigned int value)
//这个函数的返回值value的二进制位模式从左到右翻转后的值
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//法一：
//#include<stdio.h>
//#include<math.h>

//unsigned int reverse_bits(unsigned int n)
//{
//	unsigned int sum = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum += ((n >> i) & 1)*pow(2, 31 - i);
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%u\n", reverse_bits(n));
//	return 0;
//}
//法二：
//#include<stdio.h>
//unsigned int reverse_bits(unsigned int n)
//{
//	unsigned int ret = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		ret <<= 1;
//		ret |= (n >> i) & 1;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%u\n", reverse_bits(n));
//	return 0;
//}
//不使用（a + b） / 2这种方式，求两个数的平均值
//
//#include<stdio.h>
//int ave(int a, int b)
//{
//	return (a + b) >> 1;
//}
//int ave2(int a, int b)
//{
//	return (a&b) + ((a^b) >> 1);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d\n", ave(a, b));
//	printf("%d\n", ave2(a, b));
//
//	return 0;
//}
//编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1, 3, 5, 1, 3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("%d\n", ret);
//	return 0;
//}
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。

//int search(int a[3][3], int row, int col, int k, int *px, int *py)
//{
//	int i = 0;
//	int j = col - 1;
//	while (i < row &&j >= 0)
//	{
//		if (a[i][j])
//		{
//			*px = i;
//			*py = j;
//			return 1;
//		}
//		else if (a[i][j])
//		{//当前元素小于k,向下走
//			i++;
//		}
//		else
//		{
//			//当前元素大于k,向左走
//			j--;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;
//}
//int search 
//int main()
//{
//	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//}