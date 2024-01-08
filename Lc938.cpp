    // Optimal approach
class Solution {
private:
void helper(int lo, int hi, TreeNode* root, int &sum){
    if(!root) return ;
    if(root->val >= lo and root->val<= hi){
     sum+= root->val ;
     helper(lo, hi, root->left , sum);
     helper(lo, hi, root->right, sum);
     }
    else if(root->val> hi) helper(lo, hi, root->left, sum);
    else helper(lo, hi, root->right, sum);
    return;
}
public:
    int rangeSumBST(TreeNode* root, int l, int h) {
    int sum=0;
    helper(l,h,root, sum);
    return sum;   
    }
};