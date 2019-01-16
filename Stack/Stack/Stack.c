#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;

}

void StackPush(Stack* ps, STDatatype x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDatatype*)realloc(ps->_a, sizeof(STDatatype)*newcapacity);
		assert(ps->_a);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}
STDatatype StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
void StackPrint(Stack* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->_capacity; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPop(&s);
	StackSize(&s);
	StackEmpty(&s);
	StackTop(&s);
	StackPrint(&s);
}