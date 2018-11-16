#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strcmp
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char *str1, const char *str2)
{
	assert(str1!= NULL);
	assert(str2!= NULL);
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
	int ret = my_strcmp("abcdefg", "abcdef");
	if (ret > 0)
	{
		printf("hehe\n");
	}
	printf("%d\n", ret);
	return 0;
}

//长度受限的字符函数：strncap,strncat,strncmp
//strncap的模拟实现
#include<stdio.h>
#include<assert.h>
char* my_strncap(char *dest, const char *src,size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;
	while (num--)
	{
		*dest++ = *src++;
	}
	
	return ret;
	
}
int main()
{
	char arr1[] = "abcdehhhhhhhhhhhhhhh";
	char arr2[] = "hello bit";
	my_strncap(arr1, arr2, 5);
	printf("%s\n", arr1);
	return 0;
}
//strncat的模拟实现
#include<stdio.h>
#include<assert.h>
#include<string.h>
char* my_strncat(char* dest, const char* src,size_t num)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while (num--)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "world";
	int len = strlen(arr2);
	printf("%s\n",my_strncat(arr1, arr2, len));
	return 0;
}
//strncmp的模拟实现
#include<stdio.h>
#include<assert.h>
int my_strncmp(const char* str1, const char*str2,size_t num)
{
	assert(str1!= NULL);
	assert(str2!= NULL);
	while (*(str1) == *(str2))
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
	
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcda";
	printf("%d\n", my_strncmp(arr1, arr2, 4));
	return 0;
}