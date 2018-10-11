#define _CRT_SECURE_NO_WARNINGS 1
//递归方式
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
//	ret= fib(n);
//	printf("%d\n", ret);
//	return 0;
//}
//非递归方式
//#include<stdio.h>
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	if (n <= 2)
//		return 1;
//	else
//	{
//		int i = 0;
//		for (i = 3; i <= n; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//
//}
//#include<stdio.h>
//int power(int n, int k)
//{
//	if (0 == k)
//		return 1;
//	if (1==k)
//		return n;
//	else
//		return power(n,1)*power(n ,k-1);
//
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int ret = 0;
//	scanf("%d %d", &n, &k);
//	ret = power(n,k);
//	printf("%d\n", ret);
//	return 0;
//}

//#include<stdio.h>
//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = DigitSum(n);
//	printf("%d\n", ret);
//	return 0;
//
//}
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char *str)
//{
//	assert(str);
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char *str)
//{
//	assert(str);
//	char temp = 0;
//	int len = my_strlen(str);
//	if (len > 0)
//	{
//		temp = str[0];
//		str[0] = str[len - 1];
//		str[len - 1] = '\0';//递归调用，限制条件len>0，每次调用的变化str++;
//		reverse_string(str + 1);
//		str[len - 1] = temp;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//
//}
#include<stdio.h>
int Strlen(const char*str)
{
	if (*str == '\0')
		return 0;
	else return 1 + Strlen(str + 1);
}
int main()
{
	char *p = "abcdef";
	int len = Strlen(p);
	printf("%d\n", len);
	return 0;
}