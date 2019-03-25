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
//	//子类对象可以赋值给父类对象/指针/引用
//	p1 = s1;
//	Person* pp = &s1;
//	Person& rp = s1;
//	//s1 = p1;//基类对象不能赋值给派生类对象，会报错
//	Student* ps1 = (Student*)pp;//这种情况可以转换
//	ps1->_id = 10;
//	pp = &p1;
//	//Student* ps2 = (Student*)pp;//这种情况转换不会报错，但程序最终会崩溃，因为存在越界访问问题
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
//	//b.fun();//编译不通过，因为B中的fun和A中的fun构成了隐藏
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
//	string _name; // 姓名
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
//	int _num; //学号
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
//	string _name; // 姓名 
//};
//class Student : public Person 
//{
//protected:
//	int _stuNum; // 学号 
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
//	string _name;// 姓名 
//public :
//	static int _count; // 统计人的个数。 
//};
//int Person :: _count = 0;
//class Student : public Person
//{
//protected :
//	int _stuNum ; // 学号
//};
//class Graduate : public Student
//{
//protected :    
//	string _seminarCourse ; // 研究科目 
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}
//int main()
//{
//	TestPerson();
//	return 0;
//}

//class Person 
//{
//public:
//	string _name; // 姓名 
//};
//class Student :virtual public Person
//{ 
//protected :
//	int _num ; //学号 
//};
//class Teacher :virtual public Person 
//{
//protected :    
//	int _id ;// 职工编号 
//};
//class Assistant : public Student, public Teacher
//{
//protected :
//	string _majorCourse ; // 主修课程 
//};
//void Test ()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个    
//	Assistant a ;
//    a._name = "Tom";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决 
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
	//	cout << "虚表地址" << VTable << endl;
	//	for (int i = 0; VTable[i] != nullptr; ++i)
	//	{
	//		printf("第%d个虚函数地址：0x%x,->", i, VTable[i]);
	//		VFptr f = VTable[i];
	//		f();
	//	}
	//	cout << endl;
	//}
	//int main()
	//{
	//	Base b;
	//	Derive d;
	//	//思路：
	//	//取出b、d对象的前4个字节，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr 
	//	// 1.先取b的地址，强转成一个int*的指针    
	//	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
	//	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
	//	// 4.虚表指针传递给PrintVTable进行打印虚表    
	//	// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的-生成-清理解决方案，再编译就好了。 
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
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
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