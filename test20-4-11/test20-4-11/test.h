#include<stdio.h>
int b = 1;
int func()
{
	static int a = 10;
	return --a;
}