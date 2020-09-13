/*#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

//����׺���ʽת���ɺ�׺���ʽ���������

//�������ȼ�����
int prio(char x)
{
	if (x == '*' || x == '/')
		return 2;
	if (x == '+' || x == '-')
		return 1;
	if (x == '(')
		return 0;
	else
		return -1;
}
void InfixToPostfix(const string& infix, string& postfix)
{
	stack<char> s;
	int i = 0;
	while (i < infix.size())
	{
		//����ֱ�Ӹ���postfix
		if (infix[i] >= '0' && infix[i] <= '9')
			postfix.push_back(infix[i]);
		//�����������
		else
		{
			if (s.empty())
				s.push(infix[i]);
			else if (infix[i] == '(')
				s.push(infix[i]);
			else if (infix[i] == ')')
			{
				while (s.top() != '(')
				{
					postfix.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
			else
			{
				while (prio(infix[i]) <= prio(s.top()))
				{
					postfix.push_back(s.top());
					s.pop();
					if (s.empty())
						break;
				}
				s.push(infix[i]);
			}
		}
		i++;
	}
	while (!s.empty())
	{
		postfix.push_back(s.top());
		s.pop();
	}
}
//��׺���ʽ��ֵ
int cal(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
}
int postcal(string& postfix)
{
	stack<int> s;
	int i = 0;
	while (i < postfix.size())
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
			s.push(postfix[i]);
		else
		{
			int b = s.top() - '0';
			s.pop();
			int a = s.top() - '0';
			s.pop();
			int c = cal(a, b, postfix[i]);
			s.push(c + '0');
		}
		i++;
	}
	return s.top() - '0';
}
int main()
{
	cout << "��������׺���ʽ:" << endl;
	string infix;
	cin >> infix;
	string postfix;
	cout << "��׺���ʽ:" << endl;
	InfixToPostfix(infix, postfix);
	cout << postfix << endl;
	int ret = postcal(postfix);
	cout << "��׺���ʽ�ļ�������" << ret << endl;
	return 0;
}*/