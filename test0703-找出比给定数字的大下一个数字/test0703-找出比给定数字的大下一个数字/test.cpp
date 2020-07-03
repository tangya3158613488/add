#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string str;
	//当输入的字符串长度大于2时处理
	if (s.size() >= 2)
	{
		int p1 = s.size() - 1;
		int p2 = p1 - 1;
		//定义两个下标，从右往左找出第一个降序，每比较一次，两个下标指针都往左走一步
		while (s[p2] >= s[p1])
		{
			str += s[p1];
			p2--;
			p1--;
		}
		//最后比较的一次还要将p1对应的值添加到str中
		str += s[p1];
		//将str中的字符排序
		sort(str.begin(), str.end());
		int temp = s[p2];
		
		for (int i = 0; i < str.size(); i++)
		{
			if (temp < str[i])
			{
				s[p2] = str[i];
				str[i] = temp;
				break;
			}
		}
		for (int j = p2 + 1,k = 0; j < s.size(); j++,k++)
		{
			s[j] = str[k];
		}
	}
	cout << s << endl;
	return 0;
}