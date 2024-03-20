/*
You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

Here, freq(x) denotes the 
frequency
 of the character x in word, and |y| denotes the absolute value of y.

Return the minimum number of characters you need to delete to make word k-special.

 

Example 1:

Input: word = "aabcaba", k = 0

Output: 3

Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string word, int k) {
        int mini= 1e9;
        unordered_map<char, int> mp;
        for(auto it: word){
            mp[it]++;
        }
        vector<int> aa;
        for(auto it: mp) aa.push_back(it.second);
       vector<int> fr(26, 0);
        int n= aa.size();
       for(int i=0; i<n; i++){
        fr[i]= aa[i];
       }
        sort(fr.begin(), fr.end());
        int pre=0;
            for(int i=0; i<26; i++){
                int del=pre; // smaller than f[j] waalo ko poora delete kar do
                for(int j=25; j>=0; j--){
                    int diff= fr[j]-fr[i];
                    if(diff<=k) break;
                    else if(diff>k) del+= diff-k;
                 
                }
                mini= min(mini, del);
                pre+= fr[i];
            }

        return mini;

    }
};