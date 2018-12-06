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

void SListInit(SList* plist);//��ʼ������
SListNode* BuySListNode(SLTDataType x);//�����ϵͳ����һ�οռ�
void SListPushFront(SList* plist, SLTDataType x);//ͷ��
void SListPrint(SList* plist);//��ӡ����
void SListPushBack(SList* plist, SLTDataType x);//β��
void SListPopFront(SList* plist);//ͷɾ
void SListPopBack(SList* plist);//βɾ
SListNode* SListFind(SList* plist, SLTDataType x);//�Ҹ������ֵ�λ��
void SListInsertAfter(SListNode* pos, SLTDataType x);//��ĳ��λ�ò���һ��ֵ
void SListDestory(SList* plist);//�ͷ�����
void SListEraseAfter(SListNode* pos);
void Test1();
#endif //__TEST_H__