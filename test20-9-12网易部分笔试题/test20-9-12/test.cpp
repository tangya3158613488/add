#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//网易笔试：输入一个字符串，输出子串长度大于1的回文子串及个数。
//比如，输入：abbcbb
//输出：
//bb
//bbcbb
//bcb
//bb
//4
bool Ishuiwen(string& str,int left,int right,int& count)
{
	if ((right - left == 1 && str[left] == str[right]) || left == right)
	{
		count++;
		return true;
	}	
	else
	{
		if (str[left] == str[right])
			Ishuiwen(str, left + 1, right - 1, count);
		else
			return false;
	}	
}

int main()
{
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < s.size()-1; i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				if (Ishuiwen(s, i, j, count))
					cout << s.substr(i, j - i + 1) << endl;
			}
		}
	}
	cout << count << endl;
	return 0;
}
