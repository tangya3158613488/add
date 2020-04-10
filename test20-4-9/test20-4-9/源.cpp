#include<iostream>
#include<string>
using namespace std;
void Reverse(string& str, int begin, int end)
{
	char temp;
	while (begin < end)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		++begin;
		--end;
	}
}
string ReverseSentence(string& str) {
	if (str.empty())
		return "";
	int begin = 0;
	int end = str.size() - 1;
	Reverse(str, begin, end);
	begin = end = 0;
	while (str[begin] != '\0')
	{
		if (str[begin] == ' ')
		{
			++begin;
			++end;
		}
		else if (str[end] == ' ' || str[end] == '\0')
		{
			--end;
			Reverse(str, begin, end);
			begin = ++end;
		}
		else
		{
			end++;
		}
	}
	return str;
}

int main()
{
	string str("student a am i");
	ReverseSentence(str);
	cout << str;
	return 0;
}

