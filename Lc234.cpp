/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
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
    ListNode* rev(ListNode* head){
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
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slo, *fast;
        slo= head, fast= head;
        while(fast->next and fast->next->next){
            slo= slo->next;
            fast= fast->next->next;
        }
        // slo beech me hai
        slo->next= rev(slo->next);
        // slo se aage list reverse kar di
        slo= slo->next;
        ListNode* p= head;
        while(slo!=NULL){
            if(slo->val!= p->val) return false;
            else {
                slo= slo->next;
                p= p->next;
            }
        }
        return true;

    }
};