//实现单链表交换任意两个元素（不包括表头）,假设要交换的两个结点分别为p、q
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

//从头结点开始找到要交换结点的前驱结点
node* FindPre(node* head, node* p)
{
	node* cur = head;
	while (cur)
	{
		if (cur->next == p)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
node* Swap(node* head, node* p, node* q)
{
	//头结点为空，或者q为空，或者p为空，直接返回头结点
	if (head == NULL || p == NULL || q == NULL)
	{
		cout << "NULL" << endl;
		return head;
	}
	if (p->data == q->data)
		return head;
	//p,q结点相邻的情况
	if (p->next == q)
	{
		node* prev = FindPre(head, p);
		prev->next = q;
		p->next = q->next;
		q->next = p;
	}
	else if (q->next == p)
	{
		node* prev = FindPre(head, q);
		prev->next = p;
		q->next = p->next;
		p->next = q;
	}
	//p,q结点不相邻的情况  
	else if (p != q)
	{
		node* prevp = FindPre(head, p);
		node* prevq = FindPre(head, q);
		prevp->next = q;
		p->next = q->next;
		q->next = p->next;
		prevq->next = p;
	}
	return head;
}