class Solution {
public:
    int pairSum(ListNode* head) {
        // observations: if applicable
        // half from left is twin of half from right(in reverse order)
        vector<int> res;
        ListNode* p= head;
        while(p){
            res.push_back(p->val);
            p=p->next;
        }
        int maxi= 0;
        int n= res.size();
        
        for(int i=0; i<n/2; i++){
       int sum= res[i] + res[n-1-i];
       maxi= max(maxi, sum);
    }
    // time complexity: O(N)
    // space complexity: O(N)
    return maxi;
    }
};
