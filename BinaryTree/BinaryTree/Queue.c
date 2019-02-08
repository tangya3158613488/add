#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}


void QueuePush(Queue* q, QUDataType x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (q->_tail == NULL)
	{
		q->_head = q->_tail = newnode;
	}
	else
	{
		q->_tail->_next = newnode;
		q->_tail = q->_tail->_next;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
		QueueNode* newhead = q->_head->_next;
		free(q->_head);
		q->_head = newhead;
		if (newhead == NULL)
		{
			q->_tail = NULL;
		}
}
int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->_head;
	while (cur != NULL)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 0 : 1;
}

QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}
QUDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->_data;
}

