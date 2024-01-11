class Solution {
    // brute force: O(N),O(N)
    void inorder(TreeNode* root, vector<int> &nums){
        if(!root) return;
        if(!root->left and !root->right) {
            nums.push_back(root->val);
        }
        inorder(root->left, nums);
        inorder(root->right, nums);
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        inorder(root1, t1);
        inorder(root2, t2);
        if(t1==t2) return true;
        return false;

    }
};