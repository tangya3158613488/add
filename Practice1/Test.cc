1.
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2 and p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
};
2.反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* p0 = prev;
        for(int i = 0;i < m -1;i++)
        {
            prev = prev->next;
        }
        ListNode* p1 = prev->next;
        ListNode* p2 = p1;
        ListNode* p3 = p2->next;
        for(int j = m;j<n;j++)
        {
            p2->next = p3->next;
            p3->next = p1;
            prev->next = p3;
            p1 = p3;
            p3 = p2->next;
        }
        return p0->next;
    }
};
3.
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next ;
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
4.
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode* H = head;
        ListNode* cur = head->next;
        while(cur)
        {
            cur->val == val ? H->next = cur->next : H = H->next;
            cur = cur->next;
        }
        return head->val == val ? head->next : head;
        
    }
};

