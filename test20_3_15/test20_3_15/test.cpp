#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	string s = "dabcab";
	sort(s.begin(), s.end());
	size_t i = 0;
	while (i < s.size())
	{
		int count = 1;
		cout << s[i];
		while (s[i] == s[i + 1])
		{
			++i;
			++count;
		}
		cout << count;
		++i;
	}
	cout << endl;
	return 0;
}