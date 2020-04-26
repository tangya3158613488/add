#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int Q;
	while (T--)
	{
		cin >> Q;
		string str;
		queue<int> q;
		vector<int> ret;
		for (int i = 0; i < Q; i++)
		{
			cin >> str;
			int num;
			if (str == "PUSH")
			{
				cin >> num;
				q.push(num);
			}	
			else if (str == "TOP" )
			{
				if (q.empty())
					ret.push_back(-1);
				else
					ret.push_back(q.front());
			}
				
			else if (str == "POP")
			{
				if (!q.empty())
				{
					q.pop();
				}
				else
					ret.push_back(-1);
			}
			else if (str == "SIZE")
				ret.push_back(q.size());
			else if (str == "CLEAR" && !q.empty())
			{
				q.pop();
			}
		}
		for (int i = 0; i < ret.size(); i++)
		{
			cout << ret[i] << endl;
		}
	}
	return 0;
}