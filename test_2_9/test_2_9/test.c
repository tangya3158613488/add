#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void * my_memmove(void *dest, const void *src, int count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void *ret = dest;
//	if (dest < src)//从前向后
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			((char*)dest)++;
//			((char*)src)++;
//		}
//	}
//	else
//	{
//		//从后向前
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[6] = {1,2,3,4,5,6};
//	my_memmove(arr1+2, arr1, 16);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
//void * my_memcpy(void* dest, const void*src, int num)
//{
//	void *ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[6] = { 1, 2, 3, 4, 5, 6 };
//	my_memcpy(arr1 + 2, arr1, 16);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
//int main()
//{
//	char* p = "hello ""world\n";
//	printf("hello"" world\n");
//	printf("%s", p);
//	return 0;
//}
#define PRINT(FORMAT,VALUE)\
	printf("the value of " #VALUE " is " FORMAT "\n", VALUE)

