#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define CONS(a,b) int(a##e##b)
int main()
{
	printf("%d\n", CONS(2, 1));
	return 0;
}