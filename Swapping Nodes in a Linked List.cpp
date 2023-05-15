class Solution {
public:
    ListNode* swapNodes(ListNode* head, int n) {
        ListNode* p= head;
        int sz=1;
       while(p->next) {
           sz++;
        p=p->next;
       }
       p= head;
       int last= sz-n+1;
       while(p->next and n>1){
            p= p->next;
            n--;
       }
       int firstval= p->val;
       ListNode* q=head;
       int counter=1;
       while(q->next and counter!=last){
           q=q->next;
           counter++;
       }
       p->val= q->val;
       q->val = firstval;
       return head;
    }
};
