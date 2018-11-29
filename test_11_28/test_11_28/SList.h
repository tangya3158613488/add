#ifndef __TEST_H__
#define __TEST_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);//初始化链表
SListNode* BuySListNode(SLTDataType x);//向操作系统开辟一段空间
void SListPushFront(SList* plist, SLTDataType x);//头插
void SListPrint(SList* plist);//打印链表
void SListPushBack(SList* plist, SLTDataType x);//尾插
void SListPopFront(SList* plist);//头删
void SListPopBack(SList* plist);//尾删
SListNode* SListFind(SList* plist, SLTDataType x);//找给定数字的位置
void SListInsertAfter(SListNode* pos, SLTDataType x);//在某个位置插入一个值
void SListDestory(SList* plist);//释放链表
void Test1();
#endif //__TEST_H__