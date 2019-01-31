#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Test()
{
	static int i = 0;
	++i;
	printf("%d ", i);
}
int main()
{
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		Test();
	}
	return 0;
}
#include<stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	printf("%p\n", arr);//数组首元素的地址
	printf("%p\n", &arr);//数组的地址
	printf("%p\n", &arr[0]);//
	printf("%p\n", &arr + 1);
	return 0;
}
#include <stdio.h>

int main()
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3 = "hello bit.";
	char *str4 = "hello bit.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str3)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	return 0;
}
#include <stdio.h>
void test(int** ptr)
{    
	printf("num = %d\n", **ptr);   
}
int main()
{    
	int n = 10;   
	int*p = &n;   
	int **pp = &p;
	test(pp);
	test(&p);   
	return 0;
}
int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a + 0));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(*&a));
	printf("%d\n", sizeof(&a + 1));
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0] + 1));

	//字符数组
	char arr[] = {'a','b','c','d','e','f'};
	printf("%d\n", sizeof(arr)); 
	printf("%d\n", sizeof(arr+0)); 
	printf("%d\n", sizeof(*arr)); 
	printf("%d\n", sizeof(arr[1])); 
	printf("%d\n", sizeof(&arr)); 
	printf("%d\n", sizeof(&arr+1)); 
	printf("%d\n", sizeof(&arr[0] + 1));
	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));

	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0)); 
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1])); 
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));

	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0)); 
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr)); 
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));

	char *p = "abcdef";
	printf("%d\n", sizeof(p)); 
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p)); 
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));

	printf("%d\n", strlen(p));
	printf("%d\n", strlen(p + 1)); 
	printf("%d\n", strlen(*p)); 
	printf("%d\n", strlen(p[0])); 
	printf("%d\n", strlen(&p));
	printf("%d\n", strlen(&p + 1));
	printf("%d\n", strlen(&p[0] + 1));
	//二维数组 
	int a[3][4] = {0};
	printf("%d\n",sizeof(a)); 
	printf("%d\n",sizeof(a[0][0]));
	printf("%d\n",sizeof(a[0]));
	printf("%d\n",sizeof(a[0]+1));
	printf("%d\n",sizeof(*(a[0]+1)));
	printf("%d\n",sizeof(a+1));
	printf("%d\n",sizeof(*(a+1))); 
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));
	return 0;
}
