#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"


int main()
{
	static int a;
	func();
	++a;
	++b;
	printf("%d %d\n",a, func());
	printf("%d\n", b);

	return 0;
}