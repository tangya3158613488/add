#define _CRT_SECURE_NO_WARNINGS 1
//malloc的动态开辟
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int * ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态开辟
//	ptr = NULL;//每次释放完后要把ptr置为空
//	return 0;
//}

//calloc的动态开辟
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//		
//		
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//realloc的动态开辟
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int *ptr = malloc(100);
//	if (ptr != NULL)
//	{
//		//业务处理
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	int *p = NULL;
//	p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//业务处理
//	free(ptr);
//	ptr = NULL;    
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string>
void GetMemory(char **p, int num)
{
	*p = (char *)malloc(num);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str,100);
	strcpy(str, "hello");
	printf(str);
	free(str);
	str = NULL;
}