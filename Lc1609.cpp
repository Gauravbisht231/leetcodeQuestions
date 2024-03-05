/*
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Example 1:
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
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
bool isEvenOddTree(TreeNode* root) {

queue<TreeNode*> q;
q.push(root);
int level=0;

while(!q.empty()){
int oddPrev= 1e9, evenPrev= -1e9;
int size= q.size();
for(int i=0; i<size; i++){
    auto top= q.front();
    if(level%2==1 and oddPrev>top->val and top->val%2==0){
        q.pop();
        oddPrev= top->val;
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }

    else if(level%2==0 and evenPrev < top->val and top->val%2==1){
        q.pop();
        evenPrev= top->val;
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }else return false;
}
level++;
}       
return true;
    }
};