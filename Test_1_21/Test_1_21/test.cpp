#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void TestString1()
{
	//string类的常见构造
	string s1;//构造空的string类对象s1
	string s2("hello world");//用C-string字符串来构造string类对象s2
	cout << s2 << endl;
	string s3(10, 'a');//用10个字符'a'构造string类对象s3
	string s4(s2);//拷贝构造s4
	string s5(s2, 5);//用s2中前5个字符构造string对象s5

	//string类对象的容量操作
	cout << s2.size() << endl;//返回字符串的有效字符长度
	cout << s3.capacity() << endl;//返回s3空间的总大小
	s2.clear();//清空有效字符串
	cout << s2.size() << endl;//清空后size为0
	cout << s2.capacity() << endl;//但清空后capacity的大小不变
	s2.resize(10, 'a');//将s2中的有效字符个数增加到10个，多出位置用'a'进行填充
	cout << s2 << endl; //"aaaaaaaaaa"
	s2.resize(15);//将s2中的有效字符个数增加到15个,多处的位置用缺省值'\0'填充
	cout << s2 << endl;//"aaaaaaaaaa\0\0\0\0\0"
	s2.resize(3);//将s2中的有效字符个数缩小到3个
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << s2 << endl;//"aaa"
}
void TestString2()
{
	//reserve insert erase  replace push_back append
	string s("I am a student");
	s.reserve(100);
	cout << s.size()<< endl;//输出为0
	cout << s.capacity() << endl;//输出为111，说明reserve不会改变string中的有效个数元素
	s.reserve(50);
	cout << s.size() << endl;//输出为0
	cout << s.capacity() << endl;//输出为111，说明reserve参数小于string的底层空间大小时，不会将空间缩小
	s.insert(0, "hello");//在0位置插入hello
	cout << s << endl;
	s.erase(0, 5);//在0位置向后删除5个字符
	cout << s << endl;
    s.replace(0, 3, "bitxxx");//在0位置向后替换前3个字符，剩余部分接着向后覆盖
	cout << s << endl;
	s.push_back('A');//在字符串末尾插入字符'A'
	cout << s << endl;
	s.append("hehe");//在字符串末尾追加"hehe"
	cout << s << endl;
}
void TestString3()
{
	//string对象的访问操作
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
	//但是不能用s2[0] = 'h'，因为const类型对象不能修改
}
void TestString4()
{
	//获取file1的后缀
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));   
	cout << suffix << endl;
	// npos是string里面的一个静态成员变量   
	// static const size_t npos = -1; 
	// 取出url中的域名   
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
	// 删除url的协议前缀
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


