#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);
	return 0;
}
#include <stdio.h>
int main()
{
	char a = -128;
	printf("%u\n", a);
	return 0;
}
#include <stdio.h> 
int main()
{
	char a = 128;
	printf("%u\n", a);
	return 0;
}
#include<stdio.h>
int main()
{
	int i = 20;
	unsigned int j = -10;
	printf("%d\n",i + j);
	return 0;
}
#include<stdio.h>
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
	}
	return 0;
}
#include<stdio.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}
#include<stdio.h>
int main()
{
	short num = 32767;
	short int a = num + 1;
	printf("%d\n", a);
	return 0;
}
#include <stdio.h>
unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello wolrd\n");
	}
	return 0;
}