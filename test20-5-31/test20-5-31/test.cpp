#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//字符串逆序
//1.普通逆序。直接分配一个与原字符窜等长的字符数组，然后反转拷贝即可。空间复杂度为O(n)
char* Reverse1(char* s)
{
	char* q = s;
	while (*q++)
	{
		;
	}
	q -= 2;
	char* p = new char(sizeof(char)*(q - s + 2));
	char* r = p;
	while (q >= s)
	{
		*p++ = *q--;
	}
	*p = '\0';
	return r;
}
//2.原地逆序。逐个交换两边的字符
//1)设置两个指针
char* Reverse2(char* s)
{
	char* p = s;
	char* q = s;
	while (*q)
	{
		++q;
	}
	q--;
	while (q > p)
	{
		char t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}
	return s;
}
//2)递归
char* Reverse3(char* s, int left, int right)
{
	if (left >= right)
		return s;
	char t = s[left];
	s[left] = s[right];
	s[right] = t;
	Reverse3(s, left + 1, right - 1);
}
//3）非递归
char* Reverse4(char* s, int left, int right)
{
	while (left < right)
	{
		char t = s[left];
		s[left] = s[right];
		s[right] = t;
		left++;
		right--;
	}
	return s;
}
//3.不允许创建临时变量的原地逆序.异或操作和使用字符串的结束符'\0'所在的位置作为交换空间
//1)异或操作
char* Reverse5(char* s)
{
	char* r = s;
	char* p = s;
	while (*(p + 1) != '\0')
	{
		p++;
	}
	while (p > s)
	{
		*p = *p ^ *s;
		*s = *p ^ *s;
		*p = *p ^ *s;
		p--;
		s++;
	}
	return r;
}
//2)使用字符串结束符'\0'所在的位置作为交换空间
char* Reverse6(char* s)
{
	char* r = s;
	char* p = s;
	while (*p != '\0')
	{
		++p;
	}
	char* q = p - 1;
	while (q > s)
	{
		*p = *q;
		*q-- = *s;
		*s++ = *p;
	}
	*p = '\0';
	return r;
}

//整个句子按单词逆序。先按单词逆序，再整体逆序
void ReverseWord(char* p, char* q)
{
	while (p < q)
	{
		char t = *p;
		*p++ = *q;
		*q-- = t;
	}
}
char* Reverse(char* s)
{
	char* p = s;
	char* q = s;
	while (*q != '\0')
	{
		if (*q == ' ')
		{
			ReverseWord(p, q - 1);
			q++;
			p = q;
		}
		else
			q++;
	}
	ReverseWord(p, q - 1);//逆序最后一个单
	ReverseWord(s, q - 1);
	return s;
}
void Test1()
{
	char a[] = "abcdef";
	printf("%s\n", Reverse1(a));
}
void Test2()
{
	char a[] = "abcd";
	int len = sizeof(a) / sizeof(a[0]);
	//printf("%s\n", Reverse2(a));
	/*Reverse4(a, 0, len - 2);
	for (auto&e : a)
	{
		cout << e;
	}*/
	//printf("%s\n", Reverse5(a));
	printf("%s\n", Reverse6(a));
}
void Test3()
{
	char a[] = "nice to meet you";
	printf("%s\n", Reverse(a));
}
int main()
{
	//Test1();
	//Test2();
	Test3();
}