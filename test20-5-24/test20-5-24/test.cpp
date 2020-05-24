//1. 正整数序列Q中的每个元素都至少能被正整数a和b中的一个整除，现给定a和b，如何计算出Q中的前几项？，例如
//当a=3,b=5,N=6，序列为3,5,6,9,10,12
//#include<iostream>
//using namespace std;
//
//void Solve(int a, int b, int N, int* arr)
//{
//	int tempA, tempB;
//	int i = 1, j = 1;
//	for (int k = 0; k < N; k++)
//	{
//		tempA = a*i;
//		tempB = b*j;
//		if (tempA <= tempB)
//		{
//			arr[k] = tempA;
//			i++;
//		}
//		else
//		{
//			arr[k] = tempB;
//			j++;
//		}
//	}
//}
//int main()
//{
//	int arr[6];
//	Solve(3, 5, 6, arr);
//	for (int i = 0; i < 6; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//2.整型数组中除了两个数字之外，其他数字都出现了两次，如何求解这两个只出现一次的数
//思路：如果整型数组中除了一个数字之外，其他数字都出现了两次，很简单，直接将每个数字异或，最终异或的结果就是
//这个只出现一次的数字，因为相同的数字在异或后被抵消掉了。而本题可以在这个解决方案的基础上，如果能把原数组分为两个子数组
//在每个子数组中，包含一个只出现一次的数字，而其他数字都出现两次，问题就可以很容易解决：分别对两个子数组按照上述解决方案执行结果。
//首先从头到尾一次异或数组中的每个数字，因为其他数字都出现了两次，在异或中全部抵消了，所以最终得到的结果将是两个只出现一次的数字的异或结果。而这两个数字肯定不一样，那么这个异或结果肯定不为0，也就是说这个结果数字的二进制表示中至少就有一位1.在结果数字中找到第一个为1的位的位置，记为第N位，此时以第N位是不是1为标准把原数组中的数字分成两个子数组，第一个子数组中每个数字的第N为都为1，而第二个子数组的每个数字的第N位都为0。通过这种方法就可以把原数组分成两个子数组，每个子数组都只包含一个只出现一次的数字，而其他数字都出现了两次。
#include<iostream>
using namespace std;

void FindOnce(int* a, int len, int& num1, int& num2)
{
	int r1 = 0;
	for (int i = 0; i < len; i++)
	{
		r1 ^= a[i];
	}
	int bitnum = 0;
	while (!(r1 & 1))
	{
		r1 >>= 1;
		++bitnum;
	}
	int flag = 1 << bitnum;
	num1 = 0;
	num2 = 0;
	for (int j = 0; j < len; j++)
	{
		if (a[j] & flag)
			num1 ^= a[j];
		else
			num2 ^= a[j];
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 2, 4, 3, 5, 1 };
	int num1, num2;
	FindOnce(arr, sizeof(arr) / sizeof(arr[0]), num1, num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}