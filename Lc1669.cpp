/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
 
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
    ListNode* mergeInBetween(ListNode* L, int a, int b, ListNode* M) {
        ListNode *p= L , *q= L, *r= M, *s=M;
            for(int i=0; i<a-1; i++){
                q= q->next;
            }
            for(int i=0; i<b; i++){
                p= p->next;
            }
            // ListNode *x= L;
            // while(x->next) x= x->next;
            while(s->next){
                s= s->next;
            }
            q->next= M;
            s->next= p->next;
            return L;



    }
};