#include<iostream>
#include<map>
using namespace std;
//���ó������������ʵ�������������ĳ���
//1.���ݳ��������ԭ����м����������Գ���ѭ��������������һ�ν����һ��ֱ���պü�Ϊ0������С�ڱ�����Ϊֹ
int Div(int a, int b)
{
	int result = 0; 
	if (b == 0)
	{
		cout << "��������Ϊ0" << endl;
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
//���ַ���ÿ�ζ�����һ���ı��������е��ӣ��㷨Ч�ʲ��ߣ����䵱�����ǳ��󣬶���������С��ʱ��Ч�ʷǳ��͡�
//2.��λ����ʵ��
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

//���ֻ���߼�����ʵ�ּӷ�����
int Add(const int num1, const int num2)
{
	if (0 == num2)
		return num1;
	int sumtemp = num1^num2;//�����Ƽӷ����������
	int carry = (num1&num2) << 1;//��λ
	return Add(sumtemp, carry);
}
int main()
{
	cout << Add(100, 200) << endl;
	return 0;
}
//�ǵݹ�˼��
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

//���ֻ���߼�����ʵ�ֳ˷�����
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
		int last_bit = bit_map[b & ~(b - 1)];//b & ~(b - 1)�õ����һ��1��λ��
		sum += (a << last_bit);
		b &= b - 1;//ȥ�����һ��1
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