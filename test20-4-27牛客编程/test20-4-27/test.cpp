/*1.��һ��������ȵ������������ڵ�ı�Ű�������α�ţ���һ����Ϊ1���ڶ�����Ϊ2,3����������Ϊ4,5,6,7,���Դ�����
������Q��ѯ�ʣ�ÿһ��ѯ��������һ�����Ϊx�Ľ�������Ϊk�����Ƚڵ����Ƕ��٣�
��һ������һ��Q����Q��ѯ�ʣ�������Q��ÿһ��������x��k
���룺
10 1
10 2
10 3
10 4
�����
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


