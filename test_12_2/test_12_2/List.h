#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListPushBack(List* plist,LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist,LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
int ListSize(List* plist);
int ListEmpty(List* plist);
void ListReverse(List* plist);
void ListPrint(List* plist);
void ListDestory(List* plist);
void Test1();



