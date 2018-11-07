#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<windows.h>
//void find_num(int arr[], int sz)
//{
//	int i = 0;//循环变量
//	int ret = 0;//记录所有值异或的结果
//	int pos = 0;//记录ret二进制为第一个为1的位置
//	int x = 0;//将一组值异或在x，得到一个没有相同数字的值
//	int y = 0; //将一组值异或在y，得到一个没有相同数字的值
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == (ret >> i) & 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//		for (i = 0; i < sz; i++)
//		{
//			if (1 == ((arr[i] >> pos) & 1))
//			{
//				x ^= arr[i];
//			}
//			else
//				y ^= arr[i];
//			
//		}
//		printf("x=%d,y=%d\n", x, y);
//
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 1, 2, 3, 4, 5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	find_num(arr, sz);
//	return 0;
//}
//模拟实现strcap
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcap(char*dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *cp = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return cp;
}
int main()
{
	char arr1[3] ="abc";
	char arr2[3] ="def";
   my_strcap(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}