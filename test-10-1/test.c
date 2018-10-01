#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*************************\n");
	printf("*******  1.play  ********\n");
	printf("*******  0.exit  ********\n");
	printf("*************************\n");

}
void game()
{
	int num = 0;
	int ret = rand()%100 + 1;
	while (1)
	{
		printf("请猜数字:>");
		scanf_s("%d", &num);
		if (num == ret)
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		else if (num > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
#include<stdio.h>
int BinarySearch(int arr[], int key, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{

		int mid = left + (right - left) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
		return -1;
}
	int main()
	{
		int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int key = 6;
		int ret = 0;
		int sz = sizeof(arr) / sizeof(arr[0]);
		ret = BinarySearch(arr, key, sz);
		if (-1 == ret)
			printf("找不到\n");
		else
			printf("找到了:%d\n",ret);
		
		
	}
#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);
		if (0 == strcmp(password, "123456"))
		{
			break;
		}
		else
		{
			printf("密码输入错误，请再次输入！\n");
		}
	}
		if (i < 3)
			printf("登录成功\n");
		else
			printf("退出程序\n");

		return 0;
	
}
#include<stdio.h>
#include<string.h>
int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a'&&ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A'&&ch <= 'Z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0'&&ch <= '9')
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
}