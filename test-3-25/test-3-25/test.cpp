#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n = 5;
	vector<vector<int>> v{ { 5, 9, 5, 4, 4 }, { 4, 7, 4, 10, 3 }, { 2, 10, 9, 2, 3 } };
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cin >> v[i][j];
		}
	}*/

	vector<int> ret;
	for (int i = 0; i < n; i++)
	{
		int min = 0;
		if (v[0][i] < v[1][i] && v[0][i] < v[2][i])
			min = v[0][i];
		if (v[1][i] < v[0][i] && v[1][i] < v[2][i])
			min = v[1][i];
		if (v[2][i] < v[0][i] && v[2][i] < v[1][i])
			min = v[2][i];
		ret.push_back(min);
	}
	int sum = 0;
	for (int j = 0; j < ret.size() && j + 1 < ret.size(); j++)
	{
		if (ret[j] > ret[j + 1])
			sum += (ret[j] - ret[j + 1]);
		else
			sum += (ret[j - 1] + ret[j]);
	}
	cout << sum << endl;
	return 0;
}