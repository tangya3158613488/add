#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class StringFormat {
public:
	string formatString(string A, int n, vector<char> arg, int m) {
		string format;
		size_t i = 0;
		size_t k = 0;
		while (i < n)
		{
			if (A[i] == '%' && A[i + 1] == 's')
			{
				format.push_back(arg[k]);
				++k;
				i += 2;
			}
			else
			{
				format.push_back(A[i]);
				++i;
			}
		}
		while (k < m)
		{
			format.push_back(arg[k]);
			++k;
		}
		return format;
	}
};
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		if (gifts.empty() == true)
			return 0;
		map<int, int> gifts_count;
		for (int i = 0; i < n; ++i)
		{
			gifts_count[gifts[i]]++;
		}
		map<int, int>::iterator it = gifts_count.begin();
		while (it != gifts_count.end())
		{
			if (it->second > n / 2)
				return it->first;
			else
				++it;
		}
		return 0;
	}
};
int main()
{
	StringFormat str;
	string A = "A%sC%sE";
	int n = 7;
	vector<char> arg = { 'B', 'D', 'F' };
	int m = 3;
	cout << str.formatString(A, n, arg, m) << endl;
	vector<int> v = { 1, 2, 3, 2, 2 };
	Gift g;
	cout << g.getValue(v, 5) << endl;
	return 0;
}