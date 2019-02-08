#include"BinaryTree.h"
typedef struct BTNode* QUDataType;
typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);

void QueuePush(Queue* q, QUDataType x);
void QueuePop(Queue* q);

int QueueSize(Queue* q);
int QueueEmpty(Queue* q);

QUDataType QueueFront(Queue* q);
QUDataType QueueBack(Queue* q);
