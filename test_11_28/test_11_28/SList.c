#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pnode = (SListNode*)malloc(sizeof(SListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	return pnode;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newhead = BuySListNode(x);
	newhead->_next = plist->_head;
	plist->_head = newhead;
}


void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		SListNode* newtail = BuySListNode(x);
		tail->_next = newtail;
	}
}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	 plist->_head=next;
}

void SListPopBack(SList* plist)
{
	assert(plist);
	if (plist->_head->_next == NULL)//只有一个结点
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else//有两个及以上的结点
	{
		SListNode* tail = plist->_head;
		SListNode* prev = NULL;
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;
}


void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	if (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

SList list;
void Test1()
{
	SListInit(&list);
	SListPushBack(&list, 4);
	SListPushBack(&list, 3);
	SListPushBack(&list, 2);
	SListPushBack(&list, 1);
	SListPrint(&list);
	SListPopFront(&list);
	SListPopBack(&list);
	SListNode* pos = SListFind(&list, 3);
	SListInsertAfter(pos, 30);
	SListPrint(&list);
	SListDestory(&list);

}