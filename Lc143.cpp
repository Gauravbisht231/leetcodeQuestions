/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *p = head, *q = NULL, *r = NULL;
        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
        return head;
    }
    void reorderList(ListNode *head)
    {
        ListNode *slo = head, *fast = head;
        while (fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slo = slo->next;
        }
        ListNode *secondHalf = rev(slo->next);
        slo->next = nullptr; // Break the original list into two halves

        ListNode *p1 = head;
        ListNode *p2 = secondHalf;
        while (p2)
        {
            ListNode *temp1 = p1->next;
            ListNode *temp2 = p2->next;
            p1->next = p2;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }

        return;
    }
};
