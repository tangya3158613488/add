#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> coin;
	int sum = 0;//当前能组合出的最大面值
	int count = 0;//当前需要的硬币数量
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
	sort(coin.begin(), coin.end());
	if (coin[0] != 1)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> trace;
	while (1)
	{
		if (sum >= m)
		{
			cout << count << endl;
			for (auto& e : trace)
			{
				cout << e << " ";
			}
			return 0;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (coin[i] <= sum + 1)
			{
				trace.push_back(coin[i]);
				sum += coin[i];
				count++;
				break;
			}
		}
	}
	return 0;
}