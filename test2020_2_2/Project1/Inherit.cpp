#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;
class Student;
class Person{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "Tom";//����
};
class Student : public Person
{
protected:
	int _stuNum = 101;//ѧ��
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
int main()
{
	Person p;
	Student s;
	Display(p, s);
}