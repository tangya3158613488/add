#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "Tom";
//	int _age = 20;
//};
//class Student :protected Person
//{
//
//protected:
//	int _id;
//};
//class Person
//{
//public:
//
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "xiangming";
//private:
//	int _age = 18;
//};
//class Student:public Person 
//{
//protected:
//	int _id;
//};
//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}
//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Student :public Person
//{
//public:
//	int _id;
//};
//void Test()
//{
//	Student s1;
//	Person p1;
//	//���������Ը�ֵ���������/ָ��/����
//	p1 = s1;
//	Person* pp = &s1;
//	Person& rp = s1;
//	//s1 = p1;//��������ܸ�ֵ����������󣬻ᱨ��
//	Student* ps1 = (Student*)pp;//�����������ת��
//	ps1->_id = 10;
//	pp = &p1;
//	//Student* ps2 = (Student*)pp;//�������ת�����ᱨ�����������ջ��������Ϊ����Խ���������
//	//ps2->_id = 20;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//class A 
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	} 
//};
//class B : public A 
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void Test()
//{
//	B b;
//	b.fun(10); 
//	//b.fun();//���벻ͨ������ΪB�е�fun��A�е�fun����������
//};
//int main()
//{
//	Test();
//	return 0;
//}
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl; 
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		 cout << "~Person()" << endl;
//    }
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//    Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s) 
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator = (const Student& s) 
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //ѧ��
//};
//void Test ()
//{
//	Student s1 ("jack", 18);
//	Student s2 (s1); 
//	//Student s3 ("rose", 17);
//	//s1 = s3 ;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ���� 
//};
//class Student : public Person 
//{
//protected:
//	int _stuNum; // ѧ�� 
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
// }

//class Person
//{
//public:
//	Person()
//	{
//		++_count;
//	}
//protected:
//	string _name;// ���� 
//public :
//	static int _count; // ͳ���˵ĸ����� 
//};
//int Person :: _count = 0;
//class Student : public Person
//{
//protected :
//	int _stuNum ; // ѧ��
//};
//class Graduate : public Student
//{
//protected :    
//	string _seminarCourse ; // �о���Ŀ 
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}
//int main()
//{
//	TestPerson();
//	return 0;
//}

//class Person 
//{
//public:
//	string _name; // ���� 
//};
//class Student :virtual public Person
//{ 
//protected :
//	int _num ; //ѧ�� 
//};
//class Teacher :virtual public Person 
//{
//protected :    
//	int _id ;// ְ����� 
//};
//class Assistant : public Student, public Teacher
//{
//protected :
//	string _majorCourse ; // ���޿γ� 
//};
//void Test ()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��    
//	Assistant a ;
//    a._name = "Tom";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷���� 
//	/*a.Student::_name = "Tom";
//	a.Teacher::_name = "peter";*/
//}
//int main()
//{
//	Test();
//	return 0;
//}

//class A 
//{
//public:   
//	int _a;
//};
//
//// class B : public A 
//class B : public A
//{ 
//public:    
//	int _b;
//};
//// class C : public A 
//class C :public A 
//{
//public:
//	int _c; 
//};
//
//class D : public B, public C 
//{
//public:
//	int _d; 
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
	/*virtual void Func2() 
	{
		cout << "Base::Func2()" << endl;
	}*/
	/*void Func3()
	{
		cout << "Base::Func3()" << endl;
	}

private:
	int _a = 1;
};


class Derive : public Base 
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	} 
private:
	int _d = 2;
};

int main() 
{
	Base b; 
	Derive d;

	return 0;
}*/
	//class Base 
	//{ 
	//public:
	//	virtual void func1() { cout << "Base::func1" << endl; }
	//	virtual void func2() { cout << "Base::func2" << endl; }
	//private:   
	//	int a;
	//};

	//class Derive :public Base 
	//{
	//public:
	//	virtual void func1() { cout << "Derive::func1" << endl; }
	//	virtual void func3() { cout << "Derive::func3" << endl; }
	//	virtual void func4() { cout << "Derive::func4" << endl; } 
	//private: 
	//	int b; 
	//};
	//typedef void(*VFptr)();
	//void PrintVTable(VFptr VTable[])
	//{
	//	cout << "����ַ" << VTable << endl;
	//	for (int i = 0; VTable[i] != nullptr; ++i)
	//	{
	//		printf("��%d���麯����ַ��0x%x,->", i, VTable[i]);
	//		VFptr f = VTable[i];
	//		f();
	//	}
	//	cout << endl;
	//}
	//int main()
	//{
	//	Base b;
	//	Derive d;
	//	//˼·��
	//	//ȡ��b��d�����ǰ4���ֽڣ���������ָ�룬ǰ������˵���麯��������һ�����麯��ָ���ָ�����飬���������������һ��nullptr 
	//	// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��    
	//	// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
	//	// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
	//	// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���    
	//	// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������û�з�nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼����-����-�������������ٱ���ͺ��ˡ� 
	//	VFptr* VTable = (VFptr*)*(int*)&b;
	//	PrintVTable(VTable);

	//	VFptr* vTable = (VFptr*)*(int*)&d;
	//	PrintVTable(vTable);
	//	return 0;
	//}
class Base1
{
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2
{
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2
{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	Derive d;

	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);

	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);

	return 0;
}