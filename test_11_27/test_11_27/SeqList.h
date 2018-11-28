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
void SeqListInit(SeqList* ps, size_t capacity);//��ʼ��˳���
void SeqListPushBack(SeqList* ps,SLDataType x);//��˳���β������һ��x
void SeqListPrint(SeqList* ps);//��ӡ˳���
void SeqListPopBack(SeqList* ps);//��˳���β������ɾ��
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//��˳���ĳ��λ�ý��в���һ����x
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListErase(SeqList* ps, size_t pos);
int SeqListFind(SeqList*ps, SLDataType x);
size_t SeqListSize(SeqList* ps);//����˳���Ĵ�С
int SeqListEmpty(SeqList* ps);//����Ƿ�Ϊ��
void SeqListModify(SeqList* ps,size_t pos,SLDataType x);//�޸ĸ���λ�õ�ֵ
void SeqListBubbleSort(SeqList* ps);//��˳������ð������
int SeqListBinaryFind(SeqList* ps, SLDataType x);



void SeqListDestory(SeqList* ps);
#endif //__TEST_H__