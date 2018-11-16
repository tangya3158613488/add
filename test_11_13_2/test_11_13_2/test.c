#define _CRT_SECURE_NO_WARNINGS 1
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//思路：左旋一次，后面的字符向前挪动一个位置，第一个字符放到末尾
//#include<stdio.h>
//void left_rotate(char* str, int k)
//{
//	//k轮操作
//	while (k--)
//	{
//		//暂时保存第一个位置的内容
//		char temp = *str;
//		//一轮操作，左旋一次
//		char *cur = str;
//		//如果下一个字符为有效字符
//		while (*(cur + 1) != '\0')
//		{
//			//下一个位置的内容向前挪动一次
//			*cur = *(cur + 1);
//			cur++;
//		}
//		//第一个位置的内容放在末尾
//		*cur = temp;
//	}
//}
//int main()
//{
//	char arr[100];
//	int k = 0;
//	scanf("%s", arr);
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}
//左旋k次：
//第一次：逆转前k个元素
//第二次：逆转剩余元素
//第三次：字符串整体逆转
//#include<stdio.h>
//#include<string.h>
//void* reverse(char* start, char* end)
//{
//	while (start < end)
//	{
//		char temp = *start;
//		*start = *end;
//		*end = temp;
//		start++;
//		end--;
//	}
//}
//void left_rotate(char* str, int k)
//{
	//k = k%strlen(str);
	////第一次，逆转1~k
	//reverse(str, str + k - 1);
	////第二次，逆转剩余元素
	//reverse(str + k, str + strlen(str) - 1);
	////整体逆转
	//reverse(str, str + strlen(str) - 1);

//}
//int main()
//{
//	char arr[100];
//	int k = 0;
//	scanf("%s", arr);
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int is_rotate(char* dest, char* rotate)
//{
//	if (strlen(dest) != strlen(rotate))
//	{
//		return 0;
//	}
//	int len = strlen(rotate);
//	while (len--)
//	{
//		//首先旋转一次
//		right_rotate(rotate, 1);
//		//比较旋转之后的内容是否符合要求
//		if (!strcmp(dest, rotate))
//		{
//			return 1;
//		}
//	}
//	//旋转之后，得不到与dest相同的内容
//	return 0;
//}
//如果用拼接思想，判断rotate是否为dest的子串
#include<stdio.h>
#include<string.h>
int is_rotate(char* dest, char* rotate)
{
	if (strlen(dest) != strlen(rotate));
	{
		return 0;
	}
	//拼接dest
	strncat(dest, dest, strlen(dest));
	//判断rotate是否为dest的子串
	if (strstr(dest, rotate) != NULL)
	{
		return 1;
	}
	return 0;
}
//int main()
//{
//	char dset[100] = { 0 };
//	char rotate[100] = { 0 };
//	scanf("%s", dest);
//	scanf("%s", rotate);
//	printf("%d\n", is_rotate(dest, rotate));
//	return 0;
//}
//1.一个数组中只有两个数字是出现一次， 
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。
//思路：异或：找出数组中出现一次的元素，运算的结果和操作顺序无关
//异或结果中：出现1的位表明两个元素当前位一个必为0，另一个必为1
//1.根据异或结果中出现1的位置，把数组分成两个子数组
//2.每个子数组中肯定有一个元素只出现一次，其他元素都是成对出现
//3.每个子数组再去做异或运算，找出单独出现的元素
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 2, 4, 5, 4, 1 };
//	//保存单独出现的元素的异或结果
//	int ret = 0;
//	//保存异或结果中出现1的位置
//	int pos;
//	//保存单独出现的元素的值
//	int x = 0;
//	int y = 0;
//	int i;
//	int len = 0;
//	//求所有元素的异或结果
//	for (i = 0; i < len; i++)
//	{
//		ret ^= arr[i];
//	}
//	//寻找异或结果中出现1的位置
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			//保存出现1的位置
//			pos = i;
//			break;
//		}
//	}
//	//根据pos位是否为1，把数组分成两个子数组
//	//这两个子数组中肯定有一个元素只出现一次
//	for (i = 0; i < len; i++)
//	{
//		//判断pos位是否为1
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			//pos位为1的子数组
//			x ^= arr[i];
//		}
//		else
//		{
//			//pos位为0的子数组
//			y ^= arr[i];
//		}
//	}
//	printf("%d,%d\n", x, y);
//
//	return 0;
//}
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;
	empty = money;
	while (empty > 1)
	{
		//当前能换的瓶数
		total += empty / 2;
		//下一次可用的空瓶，保留不能换的空瓶
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	return 0;
}