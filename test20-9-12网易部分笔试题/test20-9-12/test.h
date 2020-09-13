//1.特征排列组合
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void combinStr(vector<string>& res, string& str, vector<vector<string>>& num, int index)
{
	if (index == num.size())
	{
		res.push_back(str);
		return;
	}
	for (int j = 0; j < num[index].size(); j++)
	{
		if (!str.empty())
			str += '-';
		combinStr(res, str + num[index][j], num, index + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<vector<string>> num(n,vector<string>());
	for (int i = 0; i < n; i++)
	{
		string s;
		while (cin >> s)
		{
			num[i].push_back(s);
			if (getchar() == '\n')    
				break;
		}
	}
	int index = 0;
	string str;
	vector<string> res;
	combinStr(res, str, num, index);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}