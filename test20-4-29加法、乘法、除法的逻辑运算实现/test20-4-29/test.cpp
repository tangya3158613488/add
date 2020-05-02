#include<iostream>
#include<map>
using namespace std;
//不用出发操作符如何实现两个正整数的除法
//1.根据除法运算的原理进行减法操作，对除数循环减被除数，减一次结果加一，直到刚好减为0或榆树小于被除数为止
int Div(int a, int b)
{
	int result = 0; 
	if (b == 0)
	{
		cout << "除数不能为0" << endl;
		return result;
	}
	while (a >= b)
	{
		result++;
		a -= b;
	}
	return result;
}int main()
{
	cout << Div(20, 3) << endl;
	return 0;
}
//此种方法每次都是以一倍的被除数进行叠加，算法效率不高，尤其当除数非常大，而被除数很小的时候，效率非常低。
//2.移位操作实现
int Div(const int a,const int b)
{
	int leftnum = a;
	int result = 0;
	while (leftnum >= b)
	{
		int multi = 1;
		while (multi*b <= (leftnum >> 1))
		{
			multi <<= 1;
		}
		result += multi;
		leftnum -= multi*b;
	}
	return result;
}
int main()
{
	cout << Div(789654328, 3) << endl;
	return 0;
}

//如何只用逻辑运算实现加法运算
int Add(const int num1, const int num2)
{
	if (0 == num2)
		return num1;
	int sumtemp = num1^num2;//二进制加法与异或类似
	int carry = (num1&num2) << 1;//进位
	return Add(sumtemp, carry);
}
int main()
{
	cout << Add(100, 200) << endl;
	return 0;
}
//非递归思想
int Add(int num1,int num2)
{
	int sum = 0;
	int a = 0;
	int b = 0;
	while ((num1&num2) > 0)
	{
		a = num1^num2;
		b = num1&num2;
		num1 = a;
		num2 = b << 1;
	}
	sum = num1^num2;
	return sum;
}
int main()
{
	cout << Add(12, 23) << endl;
	return 0;
}

//如何只用逻辑运算实现乘法运算
int Multiply(int a, int b)
{
	int sum = 0;
	bool flag = 0;
	if (b < 0)
	{
		b = -b;
		flag = 1;
	}
	map<int, int> bit_map;
	for (int i = 0; i < 32; i++)
	{
		bit_map.insert(pair<int, int>(1 << i, i));
	}
	while (b > 0)
	{
		int last_bit = bit_map[b & ~(b - 1)];//b & ~(b - 1)得到最后一个1的位置
		sum += (a << last_bit);
		b &= b - 1;//去掉最后一个1
	}
	if (flag)
		sum = -sum;
	return sum;
}
int main()
{
	cout << Multiply(3, 5) << endl;
	return 0;
}