/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.

Example 1:
Input: root = [2,1,3]
Output: 1
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // pair<value, level>
        pair<int, int> pussible={-1, -1};
        queue<TreeNode*> q;
        if (!root->left and !root->right)
            return root->val;

        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto top= q.front();
                if(!top->left and !top->right and pussible.second!= level) pussible = {top->val, level};
                if(top->left) q.push(top->left); 
                if(top->right) q.push(top->right);
                q.pop(); 
            }
            level++;
        }
        return pussible.first;
    }
};