#define _CRT_SECURE_NO_WARNINGS 1
//ʵ���ַ������������

//#include<iostream>
//#include<vector>
//using namespace std;
//void combination(char* string, int number, vector<char>& result)
//{
//	if (number == 0)
//	{
//		static int index = 1;//��static����һ����̬��������������������ִ���ڼ�һֱ����
//		vector<char>::iterator iter = result.begin();
//		cout << "��" << index++ << "������ǣ� ";
//		for (; iter < result.end(); iter++)
//			cout << *iter;
//		cout << endl;
//		return;
//	}
//	if (*string == '\0')
//		return;
//
//	result.push_back(*string);
//	combination(string + 1, number - 1, result);
//	result.pop_back();
//	combination(string + 1, number, result);
//}
//void combination(char* string)
//{
//	if (string == NULL)
//		return;
//	vector<char> result;
//	int length = strlen(string);
//	for (int i = 1; i <= length; i++)
//		combination(string, i, result);
//}
//
//int main()
//{
//	char str[] = "abc";
//	combination(str);
//	return 0;
//}

#include<iostream>
using namespace std;
void combination(char* string)
{
	int length = strlen(string);
	int n = 1 << length;//1������lengthλ����Ϊ100000����length+1λ.
	for (int i = 1; i < n; i++)//��length����3�����1��7���������п���ȡ���Ľ��
	{
		int j = 1 << (length - 1);
		int index = 0;
		while (j >= 1)
		{
			if (i&j) //λ�����㡣����011��010λ��Ľ��Ϊ010��Ϊ2������0����Ϊ��
				cout << *(string + index);
			index++;
			j = j >> 1;
		}
		cout << endl;
	}
}
int main()
{
	char* string = "abc";
	combination(string);
	return 0;
}
//���ǵ���������ַ��������ظ����ַ���������
//������������һ��string���ͣ�������һ���������������Ȼ��������������޳������ظ�����ϵ�
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//bool contains(string str, vector<string> result)
//{
//	if (result.size() == 0)
//		return false;
//	for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++)
//	{
//		if (str == *iter)
//			return true;
//	}
//	return false;
//}
//vector<string> combination(char* str)
//{
//	vector<string> vec;
//	int length = strlen(str);
//	int n = 1 << length;//1������lengthλ����Ϊ100000����length+1λ.
//	char* temp = new char[length + 1];//�������һλ�����洢��������\0��
//	for (int i = 1; i < n; i++)//��length����3�����1��7���������п���ȡ���Ľ��
//	{
//		int j = 1 << (length - 1);
//		int index = 0;
//		int k = 0;
//		for (int m = 0; m < length; m++)//������ʱ������գ�ȫ����ʼ��Ϊ��0��
//			temp[m] = '0';
//		temp[length] = '\0';
//		while (j >= 1)
//		{
//			if (i&j) //λ�����㡣����011��010λ��Ľ��Ϊ010��Ϊ2������0����Ϊ��
//				temp[k++] = *(str + index);
//			index++;
//			j = j >> 1;
//		}
//		temp[k] = '\0';
//		string ss(temp);
//		if (!contains(ss, vec))
//			vec.push_back(ss);
//	}
//	delete[] temp;
//	return vec;
//}
//int main()
//{
//	char* str = "abb";
//	vector<string> result;
//	result = combination(str);
//	int count = 1;
//	for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++)
//	{
//		cout << "��" << count << "����ϣ� " << *iter << endl;//string ���Ϳ���ֱ�����cout
//		count++;
//	}
//	return 0;
//}
