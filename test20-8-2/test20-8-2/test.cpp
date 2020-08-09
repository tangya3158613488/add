#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void swap(string& str, int i, int j)
{
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}
bool IsExist(vector<string>& res, string& str)
{
	auto it = res.begin();
	for (; it != res.end(); it++)
	{
		if (*it == str)
			return true;
	}
	return false;
}
void PermutationHelper(string &str, int start, vector<string>& res)
{
	if (start == str.size() - 1)
	{
		if (!IsExist(res, str))
		{
			res.push_back(str);
			cout << str << endl;
		}
		return;
	}

	for (int i = start; i < (int)str.size(); i++)
	{
		swap(str, start, i);
		PermutationHelper(str, start + 1, res);
		swap(str, start, i);
	}
}
vector<string> Permutation(string& str) {
	vector<string> res;
	if (!str.empty())
	{
		PermutationHelper(str, 0, res);
		sort(res.begin(), res.end());
	}
	return res;
}
int main()
{
	string str = "abc";
	Permutation(str);
	return 0;
}