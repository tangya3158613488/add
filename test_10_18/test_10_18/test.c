#define _CRT_SECURE_NO_WARNINGS 1
////ʵ��һ��ð����������һ���������鰴��С��������
//#include<stdio.h>
//void Bubble_arr(int arr[], int sz)
//{
//	int flag = 0;
//	int i = 0;
//	//ð�����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//һ��Ԫ�صıȽ�
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			break;
//	}
//}
//
//void Print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 9, 8, 6, 5, 7, 3, 4, 2, 1, 0 };
//	int sz = 0;
//	sz = sizeof(arr) / sizeof(arr[0]);
//	Print_arr(arr, sz);
//	Bubble_arr(arr, sz);
//	Print_arr(arr, sz);
//	return 0;
//}

//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1�����۰���ҷ���
//#include<stdio.h>
//int Binary_search(int arr[], int k, int left, int right)
//{
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//
//	}
//	return -1;
//}
//
//	int main()
//	{
//		int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//		int k = 6;
//		int sz = sizeof(arr) / sizeof(arr[0]);
//		int left = 0;
//		int right = sz - 1;
//
//		int ret = Binary_search(arr, k,0, sz - 1);
//		if (ret == -1)
//		{
//			printf("�Ҳ���\n");
//		}
//		else
//		{
//			printf("�ҵ���:%d\n", ret);
//		}
//		return 0;
//	}
//��ɲ�������Ϸ
#include<stdio.h>
	void menu()
	{
		printf("************************\n");
		printf("*****    1.play    *****\n");
		printf("*****    0.exit    *****\n");
		printf("************************\n");

	}
	void game()
	{
		//1.���������
		int num = 0;
		int ret = rand() % 100 + 1;
		//2.������
		while (1)
		{
			printf("�������:>");
			scanf("%d", &num);
			if (num == ret)
			{
				printf("��ϲ�㣬�¶���\n");
				break;
			}
			else if (num > ret)
			{
				printf("�´���\n");
			}
			else
			{
				printf("��С��\n");
			}
		}
	}
	int mian()
	{
		int input = 0;
		srand((unsigned int)time(NULL));
		do
		{
			menu();
			printf("��ѡ��:>");
			scanf("%d", &input);
			switch(input)
			{
				case 1:
					game();
					break;
				case 0:
					break;
				default:
					printf("ѡ�����\n");
			}
		} while (input);
		return 0;
	}