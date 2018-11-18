#define _CRT_SECURE_NO_WARNINGS 1
//字符串函数的模拟实现
//1.模拟实现strlen
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char *p)
//{
//	int count = 0;
//	assert(p != NULL);
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//int main()
//{
//	char *p = "abcdef";
//	int len = my_strlen(p);
//	printf("len=%d\n", len);
//	return 0;
//}
//
//2.strcap的模拟实现
//#include<stdio.h>
//#include<assert.h>
//char* my_strcap(char* dest, const char* src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	return ret;
//}	{
//		;
//	}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello bit";
//	my_strcap(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//3.strcat的模拟实现
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char *dest, const char*src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	
//		while (*dest != '\0')
//		{
//			dest++;
//		}
//		while (*dest++ = *src++)
//		{
//			;
//		}
//		return ret;
//
//}
//
//int main()
//{
//	char arr1[30] = "to be";
//	char arr2[] = " or not to be";
//	my_strcat(arr1,arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//模拟实现strstr
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* str1, const char*str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str2 != NULL)
	{
		return (char*)str1;
	}
	const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cp;
		}
	
		return NULL;
}
int main()
{
	char *p1 = "abcdef";
	char *p2 = "abcdabcdefghi";
	char *ret = my_strstr(p2, p1);
	printf("%s\n", ret);
	return 0
}