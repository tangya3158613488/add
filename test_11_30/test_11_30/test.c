#define _CRT_SECURE_NO_WARNINGS 1
*
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
 };

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;

	while (cur)
	{
		if (cur->val == val)
		{
			next = cur->next;
			free(cur);
			cur = next;
			if (prev == NULL)
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while (cur)
	{
		//�Ȼ�ȡ��һ���ڵ�
		next = cur->next;
		//���ĵ�ǰ�ڵ��ָ��
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;



}

//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
//
//����ָ��
//��ָ��ÿ���ƶ�һ��
//��ָ��ÿ���ƶ�����
//����ָ���ߵ�����β��ʱ��ָ�������ߵ������м�λ��




