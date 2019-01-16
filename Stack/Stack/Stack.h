#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

typedef int STDatatype;
typedef struct Stack
{
	STDatatype* _a;
	int _top;//Õ»¶¥
	int _capacity;//ÈÝÁ¿
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDatatype x);
void StackPop(Stack* ps);
STDatatype StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void StackPrint(Stack* ps);
void TestStack();

