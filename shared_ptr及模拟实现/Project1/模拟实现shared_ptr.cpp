#define _CRT_SECURE_NO_WARNINGS 1
#include "Shared_ptr.h"
#include <iostream>
using namespace std;
int main()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << &sp1 << " " << &sp2 << endl;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp1.Get() << endl;
	cout << sp2.Get() << endl;

	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << &sp2 << " " << &sp3 << endl;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	cout << sp1.Get() << endl;
	cout << sp2.Get() << endl;
	cout << sp3.Get() << endl;

	sp1 = sp3;
	cout << *sp3 << endl;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	cout << sp1.Get() << endl;
	cout << sp2.Get() << endl;
	cout << sp3.Get() << endl;
}