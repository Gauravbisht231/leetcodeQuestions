// brute force solution
class Solution {
public:
   vector<int> elements;
   void helper(TreeNode* root){
        if(!root)return;
        elements.push_back(root->val);
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
        return;
   }
    int rangeSumBST(TreeNode* root, int lo, int hi) {
        // [lo, hi]
     helper(root);
    //  sort(elements.begin(), elements.end());
     int sum=0;
     for(auto it: elements){
         if(it>=lo and it<= hi) sum+=it;
     }
     return sum;

    }
};