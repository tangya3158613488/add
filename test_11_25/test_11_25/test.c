#define _CRT_SECURE_NO_WARNINGS 1
//malloc�Ķ�̬����
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int * ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬����
//	ptr = NULL;//ÿ���ͷ����Ҫ��ptr��Ϊ��
//	return 0;
//}

//calloc�Ķ�̬����
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
//		
//		
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//realloc�Ķ�̬����
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int *ptr = malloc(100);
//	if (ptr != NULL)
//	{
//		//ҵ����
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
//	//ҵ����
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