#define _CRT_SECURE_NO_WARNINGS 1
字符串函数的模拟实现
1.模拟实现strlen
#include<stdio.h>
#include<assert.h>
int my_strlen(const char *p)
{
	int count = 0;
	assert(p != NULL);
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}
int main()
{
	char *p = "abcdef";
	int len = my_strlen(p);
	printf("len=%d\n", len);
	return 0;
}

2.strcap的模拟实现
#include<stdio.h>
#include<assert.h>
char* my_strcap(char* dest, const char* src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	return ret;
}	{
		;
	}

int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "hello bit";
	my_strcap(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
3.strcat的模拟实现
#include<stdio.h>
#include<assert.h>
char* my_strcat(char *dest, const char*src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	
		while (*dest != '\0')
		{
			dest++;
		}
		while (*dest++ = *src++)
		{
			;
		}
		return ret;

}

int main()
{
	char arr1[30] = "to be";
	char arr2[] = " or not to be";
	my_strcat(arr1,arr2);
	printf("%s\n", arr1);
	return 0;
}

模拟实现strstr
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char*str1, const char*str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
    const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;
	if (*str2 == '\0')
		return (char*)str1;
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
			return cp;
		cp++;
	}
	return NULL;
}
	int main()
	{
		char *p1 = "abcdef";
		char *p2 = "abcdabcdefghi";
		char *ret = my_strstr(p2, p1);//在p2里查找p1
		printf("%s\n", ret);
		return 0;
	}

模拟实现strchr
#include<stdio.h>
#include<assert.h>
char * my_strchr(const char *str, char c)
{
	assert(str != NULL);
	while (*str && (*str != (char)c))
	{
		str++;
	}
	if ((char)c == *str)
		return (char *)str;
	return NULL;
}
int main()
{
	char arr[] = "abcdef";
	char p = 'd';
	char *ret = my_strchr(arr, p);
	printf("%s", ret);
	return 0;
}

模拟实现strcmp
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char*str1, const char*str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	int ret = my_strcmp("abc", "abcdef");
	if (ret > 0)
	{
		printf("hehe\n");
	}
	printf("%d\n", ret);
	return 0;
}

模拟实现memcap
#include<stdio.h>
#include<assert.h>
void * my_memcpy(void* dest, const void*src, int count)
{
	void *ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

模拟实现memmove
#include<stdio.h>
#include<assert.h>
void * my_memmove(void*dest, const void*src,int count)
{
	assert(dest != NULL);
	assert(src != NULL);
	void *ret = dest;
	if (dest < src)//从前向后
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
					((char*)dest)++;
					((char*)src)++;
		}
	}
	else
	{
		从后向前
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6 };
	int arr2[20] = { 0 };
	my_memmove(arr2, arr1, sizeof(arr1));
	return 0;
}