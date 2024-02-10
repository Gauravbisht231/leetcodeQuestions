/*
                                            Longest String Chain

You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
bool check(string &a, string &b){
   if(a.size()-b.size()!=1) return 0;
   int apointer=0, bpointer=0;
   while(apointer<a.size()){
       if(a[apointer]== b[bpointer]) {
           apointer++;
           bpointer++;
       }
       else {
           apointer++;
       }
   }
   return (apointer==a.size() and bpointer==b.size());
}
static bool comp(string &a, string &b){
    return a.size()<b.size();
}
public:
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        vector<int> dp(n+1, 1);
        sort(words.begin(), words.end(), comp);
        int maxlen=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if( check(words[i], words[j]) and (dp[i]<=dp[j])) dp[i]= dp[j]+1;
                maxlen= max(maxlen, dp[i]); 
            }
        }
        return maxlen;
    }
};