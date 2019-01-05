#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int *pa = &a;
//	int* *ppa = &pa;
//	//a的地址存放在pa中，pa的地址存放在ppa中
//	//pa是一级指针，而ppa是二级指针,*ppa通过对ppa中的地址进行解引用，这样找到的是pa,*ppa访问的就是pa
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char ch = 'w';
//	char *pc = &ch;
//	*pc = 'e';
//	const char *p = "abcdef";
//	//*p = 'q';不能修改*p；里面的内容
//	printf("%s\n", p);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char *p1 = "abcdef";
//	char *p2 = "abcdef";
//	if (arr1 == arr2)
//	{
//		printf("arr1==arr2\n");//no
//	}
//	if (p1==p2)
//	{
//		printf("p1==p2\n");//ok
//	}
//	return 0;
//}

#include<stdio.h>
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	do
	{
		menu()
			printf("请选择：>");
	}
	return 0
}