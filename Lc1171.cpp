/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.
(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
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
    int findN(ListNode* head) {
        ListNode* p = head;
        int nodes = 0;
        while (p) {
            nodes++;
            p = p->next;
        }
        cout << nodes << endl;
        return nodes;
    }

public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int n = findN(head);
        unordered_map<int, ListNode*> mp; // map<sum, node position>
        vector<int> pre(n, 0);
        // pre[0]= head->val;
        ListNode* p = head;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                pre[0] = p->val;
            else
                pre[i] = pre[i - 1] + p->val;
            p = p->next;
        }
// if(pre[n-1]==0) return NULL;
        mp[0] = dummy;
        p = head;
        for (int i = 0; i < n; i++) {
            int curSum = pre[i];

            if (mp.find(curSum) != mp.end()) {
                auto foundNode = mp[curSum];
                auto mover= foundNode->next;
                auto moverSum= curSum;
                while(mover!= p ) {
                    moverSum+= mover->val;
                    mp.erase(moverSum);
                    mover= mover->next;
                    
                }
                foundNode->next = p->next;
            }else mp[curSum] = p;
            
            p = p->next;
        }
       
       return dummy->next;
    }
};
