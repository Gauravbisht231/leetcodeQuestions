/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
*/
#include<bits/stdc++.h>
using namespace std; 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q, *r;
        p= head;
        q= NULL;
        r= NULL;
        while(p){
            r= q;
            q= p;
            p= p->next;
            q->next=r;
        }
        head= q;
        return head;
    }
};