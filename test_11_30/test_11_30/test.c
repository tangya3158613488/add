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
		//先获取下一个节点
		next = cur->next;
		//更改当前节点的指向
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;



}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//
//快慢指针
//慢指针每次移动一个
//快指针每次移动两个
//当快指针走到链表尾部时慢指针整好走到链表中间位置




