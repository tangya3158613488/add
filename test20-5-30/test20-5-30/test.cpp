//ʵ�ֵ���������������Ԫ�أ���������ͷ��,����Ҫ�������������ֱ�Ϊp��q
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

//��ͷ��㿪ʼ�ҵ�Ҫ��������ǰ�����
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
	//ͷ���Ϊ�գ�����qΪ�գ�����pΪ�գ�ֱ�ӷ���ͷ���
	if (head == NULL || p == NULL || q == NULL)
	{
		cout << "NULL" << endl;
		return head;
	}
	if (p->data == q->data)
		return head;
	//p,q������ڵ����
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
	//p,q��㲻���ڵ����  
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