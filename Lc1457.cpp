#include<bits/stdc++.h>
using namespace std;
class Solution {
int res=0;
void helper(TreeNode* root, int x){
if(!root) return;
// int cur= root->val;
x= x ^ (1<<root->val);
if(root->left==NULL and root->right==NULL){
if((x & (x-1))==0) res++;
}
helper(root->left, x);
helper(root->right, x);
}
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root, 0);
        return res;
    }
};



/**
class Solution {
public:
int res=0;
int isPseudo(vector<int>& fre){
    int odd=0;
    for(int i=1; i<10; i++){
        if(fre[i]%2==1 and fre[i]!=0) odd++;
    }
    return odd<=1;
}
void helper(TreeNode* root, vector<int> &fre){
    if(!root) return;
    fre[root->val]++;
    if(root->left== NULL and root->right==NULL){
        res+= isPseudo(fre);
    }
    helper(root->left, fre);
    helper(root->right, fre);
    fre[root->val]--;
}
int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> fre(10, 0);
        helper(root, fre);
return res;
    }
};
 */