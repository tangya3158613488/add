#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void TestString1()
{
	//string��ĳ�������
	string s1;//����յ�string�����s1
	string s2("hello world");//��C-string�ַ���������string�����s2
	cout << s2 << endl;
	string s3(10, 'a');//��10���ַ�'a'����string�����s3
	string s4(s2);//��������s4
	string s5(s2, 5);//��s2��ǰ5���ַ�����string����s5

	//string��������������
	cout << s2.size() << endl;//�����ַ�������Ч�ַ�����
	cout << s3.capacity() << endl;//����s3�ռ���ܴ�С
	s2.clear();//�����Ч�ַ���
	cout << s2.size() << endl;//��պ�sizeΪ0
	cout << s2.capacity() << endl;//����պ�capacity�Ĵ�С����
	s2.resize(10, 'a');//��s2�е���Ч�ַ��������ӵ�10�������λ����'a'�������
	cout << s2 << endl; //"aaaaaaaaaa"
	s2.resize(15);//��s2�е���Ч�ַ��������ӵ�15��,�ദ��λ����ȱʡֵ'\0'���
	cout << s2 << endl;//"aaaaaaaaaa\0\0\0\0\0"
	s2.resize(3);//��s2�е���Ч�ַ�������С��3��
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << s2 << endl;//"aaa"
}
void TestString2()
{
	//reserve insert erase  replace push_back append
	string s("I am a student");
	s.reserve(100);
	cout << s.size()<< endl;//���Ϊ0
	cout << s.capacity() << endl;//���Ϊ111��˵��reserve����ı�string�е���Ч����Ԫ��
	s.reserve(50);
	cout << s.size() << endl;//���Ϊ0
	cout << s.capacity() << endl;//���Ϊ111��˵��reserve����С��string�ĵײ�ռ��Сʱ�����Ὣ�ռ���С
	s.insert(0, "hello");//��0λ�ò���hello
	cout << s << endl;
	s.erase(0, 5);//��0λ�����ɾ��5���ַ�
	cout << s << endl;
    s.replace(0, 3, "bitxxx");//��0λ������滻ǰ3���ַ���ʣ�ಿ�ֽ�����󸲸�
	cout << s << endl;
	s.push_back('A');//���ַ���ĩβ�����ַ�'A'
	cout << s << endl;
	s.append("hehe");//���ַ���ĩβ׷��"hehe"
	cout << s << endl;
}
void TestString3()
{
	//string����ķ��ʲ���
	string s1("hello world");
	const string s2("Hello world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	//���ǲ�����s2[0] = 'h'����Ϊconst���Ͷ������޸�
}
void TestString4()
{
	//��ȡfile1�ĺ�׺
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));   
	cout << suffix << endl;
	// npos��string�����һ����̬��Ա����   
	// static const size_t npos = -1; 
	// ȡ��url�е�����   
	string url("http://www.cplusplus.com/reference/string/string/find/");  
	cout << url << endl;    size_t start = url.find("://");   
	if (start == string::npos)  
	{     
		cout << "invalid url" << endl;  
		return;   
	}   
	start += 3;  
	size_t finish = url.find('/', start);  
	string address = url.substr(start, finish - start);
	cout << address << endl; 
	// ɾ��url��Э��ǰ׺
	pos = url.find("://");   
	url.erase(0, pos+3);   
	cout<<url<<endl;
}
int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	TestString4();
	return 0;
}


