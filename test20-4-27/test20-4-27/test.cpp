/*1.给一颗无限深度的满二叉树，节点的编号按层次依次编号，第一层编号为1，第二层编号为2,3，第三层编号为4,5,6,7,，以此类推
接下来Q此询问，每一次询问让你找一个编号为x的结点在深度为k的祖先节点编号是多少？
第一行输入一个Q代表Q次询问，接下来Q行每一行两个数x和k
输入：
10 1
10 2
10 3
10 4
输出：
1
2
5
-1
*/
#include<iostream>
#include<vector>
using namespace std;
int solve(long long x, int k)
{
	int level = log(x) / log(2) + 1;
	if (k >= level)
		return -1;
	int gap = level - k;
	long long res = x;
	while (gap--)
	{
		res /= 2;
	}
	return res;
}
int main()
{
	int Q;
	cin >> Q;
	vector<int> ret;
	while (Q--)
	{
		long long x;
		int k;
		cin >> x >> k;
		ret.push_back(solve(x, k));
	}
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
	return 0;
}


