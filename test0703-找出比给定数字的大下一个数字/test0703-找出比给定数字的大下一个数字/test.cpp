#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string str;
	//��������ַ������ȴ���2ʱ����
	if (s.size() >= 2)
	{
		int p1 = s.size() - 1;
		int p2 = p1 - 1;
		//���������±꣬���������ҳ���һ������ÿ�Ƚ�һ�Σ������±�ָ�붼������һ��
		while (s[p2] >= s[p1])
		{
			str += s[p1];
			p2--;
			p1--;
		}
		//���Ƚϵ�һ�λ�Ҫ��p1��Ӧ��ֵ��ӵ�str��
		str += s[p1];
		//��str�е��ַ�����
		sort(str.begin(), str.end());
		int temp = s[p2];
		
		for (int i = 0; i < str.size(); i++)
		{
			if (temp < str[i])
			{
				s[p2] = str[i];
				str[i] = temp;
				break;
			}
		}
		for (int j = p2 + 1,k = 0; j < s.size(); j++,k++)
		{
			s[j] = str[k];
		}
	}
	cout << s << endl;
	return 0;
}