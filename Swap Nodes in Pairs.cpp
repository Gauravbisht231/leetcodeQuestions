class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy= new ListNode();
        ListNode* point= dummy;
        dummy->next= head;
while(point->next and point->next->next){
ListNode* p, *q;
p= point->next;
q= point->next->next;
p->next= q->next;
q->next= p;
point->next= q; // first time dummy is not lost because of  this
point= p;
}
return dummy->next;
    }
};
