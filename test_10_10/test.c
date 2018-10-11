#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (5 == i)
//			continue;
//		printf("%d ", i);//输出1 2 3 4然后死循环
//		i++;
//	} while (i <= 10);
//	return 0;
//}

//用递归方式实现求第n个斐波那契数
//#include<stdio.h>
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//}
//用非递归方式实现求第n个斐波那契数
#include<stdio.h>
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (n <= 2)
		return 1;
	else
	{
		int i = 0;
		for (i = 2; i < n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c; 
	}

}
int main()
{
	int n = 0;
	scanf("%d\n", &n);
	printf("%d\n",fib(n));
	return 0;
}


//创建一个数组实现函数init()初始化数组、
//实现empty()清空数组、
//实现reverse()函数完成数组元素的逆置
//#include<stdio.h>
//void Init(int arr[], int sz, int set)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = set;
//	}
//}
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void Empty(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void Reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz-1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz, 1);//初始化数组
//	Print(arr, sz);//打印数组
//	Empty(arr, sz);//清空数组
//	Reverse(arr, sz);//逆置数组
//	return 0;
//}