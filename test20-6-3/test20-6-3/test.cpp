#define _CRT_SECURE_NO_WARNINGS 1
//实现字符串的所有组合

//#include<iostream>
//#include<vector>
//using namespace std;
//void combination(char* string, int number, vector<char>& result)
//{
//	if (number == 0)
//	{
//		static int index = 1;//用static声明一个静态持续变量，在整个程序执行期间一直存在
//		vector<char>::iterator iter = result.begin();
//		cout << "第" << index++ << "个组合是： ";
//		for (; iter < result.end(); iter++)
//			cout << *iter;
//		cout << endl;
//		return;
//	}
//	if (*string == '\0')
//		return;
//	/*我们有两种选择：第一是把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
//	第二是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符*/
//	result.push_back(*string);
//	combination(string + 1, number - 1, result);
//	result.pop_back();
//	combination(string + 1, number, result);
//}
//void combination(char* string)
//{
//	if (string == NULL)
//		return;
//	vector<char> result;
//	int length = strlen(string);
//	for (int i = 1; i <= length; i++)
//		combination(string, i, result);
//}
//
//int main()
//{
//	char str[] = "abc";
//	combination(str);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void combination(char* string)
//{
//	int length = strlen(string);
//	int n = 1 << length;//1向左移length位，变为100000，共length+1位.
//	for (int i = 1; i < n; i++)//若length等于3，则从1到7，既是所有可能取到的结果
//	{
//		int j = 1 << (length - 1);
//		int index = 0;
//		while (j >= 1)
//		{
//			if (i&j) //位与运算。比如011与010位与的结果为010，为2，不是0所以为真
//				cout << *(string + index);
//			index++;
//			j = j >> 1;
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	char* string = "abc";
//	combination(string);
//	return 0;
//}
//考虑到了输入的字符串中有重复的字符串的情形
//把输出结果保存一个string类型，另外找一个容器保存计算结果然后这个计算结果是剔除掉了重复的组合的
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool contains(string str, vector<string> result)
{
	if (result.size() == 0)
		return false;
	for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++)
	{
		if (str == *iter)
			return true;
	}
	return false;
}
vector<string> combination(char* str)
{
	vector<string> vec;
	int length = strlen(str);
	int n = 1 << length;//1向左移length位，变为100000，共length+1位.
	char* temp = new char[length + 1];//多出来的一位用来存储结束符‘\0’
	for (int i = 1; i < n; i++)//若length等于3，则从1到7，既是所有可能取到的结果
	{
		int j = 1 << (length - 1);
		int index = 0;
		int k = 0;
		for (int m = 0; m < length; m++)//对于临时数组清空，全部初始化为‘0’
			temp[m] = '0';
		temp[length] = '\0';
		while (j >= 1)
		{
			if (i&j) //位与运算。比如011与010位与的结果为010，为2，不是0所以为真
				temp[k++] = *(str + index);
			index++;
			j = j >> 1;
		}
		temp[k] = '\0';
		string ss(temp);
		if (!contains(ss, vec))
			vec.push_back(ss);
	}
	delete[] temp;
	return vec;
}
int main()
{
	char* str = "abb";
	vector<string> result;
	result = combination(str);
	int count = 1;
	for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++)
	{
		cout << "第" << count << "个组合： " << *iter << endl;//string 类型可以直接输出cout
		count++;
	}
	return 0;
}
