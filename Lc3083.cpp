/*
Given a string s, find any 
substring
 of length 2 which is also present in the reverse of s.

Return true if such a substring exists, and false otherwise.

 

Example 1:

Input: s = "leetcode"

Output: true

Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".

Example 2:

Input: s = "abcba"

Output: true

Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubstringPresent(string s) {
    // bool one= false, two=false;
        int n= s.size();
        // check 
        unordered_map<string , int> mp;
        for(int i=0; i<n-1; i++){
            string sub= s.substr(i, 2);
            mp[sub]++;
        }
        reverse(s.begin(), s.end());
        for(int i=0; i<n-1; i++ ){
        string sub= s.substr(i, 2);
            if(mp.find(sub)!= mp.end()) return true;
        }
        return false;
    }
};