#define _CRT_SECURE_NO_WARNINGS 1
//���һ������ʵ���жϵ�ǰ�������ֽ���
//����һ��
//#include<stdio.h>
//int check_sys()
//{
//	int i = 1;
//	return (*(char*)&i);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}
//��������
//#include<stdio.h>
//int check_sys()
//{
//	union Un
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);//-1,-1,225
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a = -128;//��Ҫ��������
//	printf("%u\n", a);//4294967168
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a = 128;
//	printf("%u\n", a);//4294967168
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);//-10
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);//��ѭ��4294967168
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));//128+127=255
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char ch = 'w';
//	char *pc = &ch;
//	*pc = 'w';
//	return 0;

//ģ��ʵ��strcat
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char *dest,const char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char *p = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return p;
//
//}
//int main()
//{
//	char arr1[30] = "to be";
//	char arr2[] = " or not to be";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//ģ��ʵ��strcap
#include<stdio.h>
#include<assert.h>
char * my_strcap(char*dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *cp = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return cp;
}
int main()
{
	char arr1[20] = "abc";
	char arr2[3] = "def";
	my_strcap(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}