#ifndef __TEST_H__
#define __TEST_H__
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList;
void SeqListInit(SeqList* ps, size_t capacity);//初始化顺序表
void SeqListPushBack(SeqList* ps,SLDataType x);//在顺序表尾部插入一个x
void SeqListPrint(SeqList* ps);//打印顺序表
void SeqListPopBack(SeqList* ps);//在顺序表尾部进行删除
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//在顺序表某个位置进行插入一个数x
void SeqListPopFront(SeqList* ps);//头删
void SeqListErase(SeqList* ps, size_t pos);
int SeqListFind(SeqList*ps, SLDataType x);
size_t SeqListSize(SeqList* ps);//计算顺序表的大小
int SeqListEmpty(SeqList* ps);//检查是否为空
void SeqListModify(SeqList* ps,size_t pos,SLDataType x);//修改给定位置的值
void SeqListBubbleSort(SeqList* ps);//对顺序表进行冒泡排序
int SeqListBinaryFind(SeqList* ps, SLDataType x);



void SeqListDestory(SeqList* ps);
#endif //__TEST_H__