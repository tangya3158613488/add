#define _CRT_SECURE_NO_WARNINGS 1
////�����������α�����ֵ��������ֵ�����ݽ��н���
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int tmp = a;
//	a =b;
//	b = tmp;
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}

//����������ʱ����������������������
//#include<stdio.h>
//void Swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}

//��ʮ�������е����ֵ
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 2, 4, 9, 5, 12, 56, 98, 67, 34, 22 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int max = 0;
//	max = arr[0];
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i]>max)
//	
//			max = arr[i];
//	}
//	printf("max=%d\n", max);
//
//	return 0;
//}

//������������С�������
//#include<stdio.h>
//void Swap(int *px, int *py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("��������������:>\n");
//	scanf("%d%d%d", &a, &b, &c);
//	if (a > b)
//	{
//		Swap(&a, &b);
//	}
//	if (a > c)
//	{
//		Swap(&a, &c);
//	}
//	if (b > c)
//	{
//		Swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//�������������Լ��
//#include<stdio.h>
//int main()
//{
//	int a = 9;
//	int b = 24;
//	int c = 0;
//	while (c = a%b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}

//��������ͬ��С���������ݽ��н���
//#include<stdio.h>
//void print_arr(int arr[5], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr1[] = { 1, 3, 5, 7, 9 };
//	int arr2[] = { 0, 2, 4, 6, 8 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	print_arr(arr1, sz);
//	print_arr(arr2, sz);
//	return 0;
//}
