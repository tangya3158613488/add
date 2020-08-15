#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int num1, num2;
//	int count = 1;
//	vector<vector<int>> vv;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (i == 0)
//		{
//			num1 = a;
//			num2 = b;
//		}
//		vector<int> v;
//		if (a != num1 && a != num2 && b != num1 && b != num2)
//		{
//			count++;
//			v.push_back(a);
//			v.push_back(b);
//		}
//		vv.push_back(v);
//	}
//	cout << count << endl;
//	if (count > 1)
//	{
//		for (int i = 0; i < count; i++)
//		{
//			for (int j = 0; j < vv[i].size(); j++)
//			{
//				cout << vv[i][j] << ' ';
//			}
//			cout << endl;
//		}
//	}
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 0;
//	vector<string> v;
//	string s;
//	string start;
//	string end;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s;
//		v.push_back(s);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		//如果start为空，就将当前的字符串第一个单词赋给start
//		if (start.empty())
//		{
//			int j = 0;
//			while (v[i][j] != ' ')
//			{
//				j++;
//			}
//			start = v[i].substr(0, j - 1);
//		}
//		//否则每次循环更新字符串end
//		else
//		{
//			int j = v[i].size() - 1;
//			while (v[i][j] != ' ')
//			{
//				j--;
//			}
//			end = v[i].substr(j + 1, v[i].size() - 1);
//		}
//		//如果start和end字符串相等，计数器加1
//		if (start == end)
//		{
//			count++;
//			start.clear();
//			end.clear();
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> divingBoard(int a, int b, int k)
//{
//	vector<int> v;
//	int num1 = a;
//	int num2 = b;
//	a = min(num1, num2);
//	b = max(num1, num2);
//	if (k == 0)
//		return v;
//	if (a == b)
//	{
//		v.push_back(a * k);
//		return v;
//	}
//		
//	int t = a * k;
//	v.push_back(t);
//	for (int i = 1; i <= k; i++)
//	{
//		t -= a;
//		t += b;
//		v.push_back(t);
//	}
//	return v;
//}
//int main()
//{
//	vector<int> res;
//	int a, b, k;
//	cin >> a >> b >> k;
//	res = divingBoard(a, b, k);
//	if (res.size() == 0)
//	{
//		cout << "[]" << endl;
//		return 0;
//	}
//	cout << '[';
//	for (int i = 0; i < res.size() - 1; i++)
//	{
//		cout << res[i] << ',';
//	}
//	cout << res[res.size() - 1] << ']'<<endl;
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct TreeNode
{
	int val;
	vector<TreeNode*> child;
	TreeNode(int x)
		:val(x)
	{}
};
bool flag;
map<string, TreeNode*> m;
int solve(TreeNode* root)
{
	if (root = nullptr)
		return 0;
	int sum = 0;
	for (int i = 0; i < root->child.size(); i++)
	{
		sum = max(sum, solve(root->child[i]));
	}
	sum += root->val;
	if (root->val == -1)
	{
		flag = false;
	}
	return sum;
}
int main()
{
	string s;
	cin >> s;
	s += '|';
	flag = true;
	for (int i = 0; i < s.size(); i++)
	{
		int k = 0;
		while (s[i + k] != '`')
		{
			k++;
		}
		string name = s.substr(i, k);
		i += k + 1;
		k = 0;
		int sum = 0;
		while (s[k + i] != '`')
		{
			sum = sum * 10 + s[i + k] - '0';
			k++;
		}
		i += k;
		TreeNode* t;
		if (m.find(name) == m.end())
		{
			t = new TreeNode(sum);
			m[name] = t;
		}
		else
		{
			t = m[name];
		}
		t->val = sum;
		while (s[i] != '|')
		{
			i++;
			k = 0;
			while (s[i + k] != ',' && s[i + k] != '|')
			{
				k++;
			}
			string name = s.substr(i, k);
			if (name == "END")
			{
				i += k;
				if (t->child.size() != 0)
				{
					cout << -1 << endl;
					return 0;
				}
				break;
			}
			TreeNode* p;
			if (m.find(name) == m.end())
			{
				p = new TreeNode(-1);
				m[name] = p;
			}
			else
			{
				p = m[name];
			}
			t->child.push_back(p);
			i += k;
		}
	}
	int ans = solve(m["HEAD"]);
	if (flag == false)
		ans = -1;
	cout << ans << endl;
	return 0;
}