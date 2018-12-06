#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(-1);
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
	
}

void ListPushBack(List* plist,LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;
}

void ListPrint(List* plist)
{
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	printf("<-head->");
	while (cur != head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");

}

void ListPopBack(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;
	free(tail);
	tailprev->_next = head;
	head->_prev = tailprev;
}


void ListPushFront(List* plist,LTDataType x)
{
	assert(plist);
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;
}

void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;
	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;

}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}



void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	newnode->_next = pos;
	pos->_prev = newnode;
	prev->_next = newnode;
	newnode->_prev = prev;
}


void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}


void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* node = ListFind(plist, x);
	if (node != NULL)
	{
		ListErase(node);
	}
}

int ListSize(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	int size = 0;
	while (cur != plist->_head)
	{
		++size;
		cur = cur->_next;
	}
	printf("%d\n", size);
	return size;
}

int ListEmpty(List* plist)
{
	assert(plist);
	printf("%d\n", plist->_head->_next == plist->_head ? 0 : -1);
	return 0;
}

void ListReverse(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* ptmp = cur->_next;
		cur->_next = cur->_prev;
		cur->_prev = ptmp;
		cur = cur->_prev;
	}
	ListNode* ptmp = head->_next;
	head->_next = head->_prev;
	head->_prev = ptmp;
}



void ListDestory(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	free(head);
	head = NULL;
}
 List list;

void Test1()
{
	ListInit(&list);
	ListPushBack(&list,1);
	ListPushBack(&list,2);
	ListPushBack(&list,3);
	ListPushBack(&list,4);
	ListPushBack(&list,5);
	ListPushBack(&list,6);
	ListPrint(&list);
	ListPopBack(&list);
	ListPrint(&list);
	ListPushFront(&list, 10);
	ListPrint(&list);
	ListPopFront(&list);
	ListPrint(&list);
	ListNode* pos = ListFind(&list, 3);
	ListInsert(pos, 8);
	ListPrint(&list);
	ListErase(pos);
	ListPrint(&list);
	ListRemove(&list,5);
	ListPrint(&list);
	ListSize(&list);
	ListEmpty(&list);
	ListReverse(&list);
	ListPrint(&list);
	ListDestory(&list);
}