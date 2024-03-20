/*
You are given a string s and a character c. Return the total number of 
substrings
 of s that start and end with c.

 

Example 1:

Input: s = "abada", c = "a"

Output: 6

Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".

Example 2:

Input: s = "zzz", c = "z"

Output: 6

Explanation: There are a total of 6 substrings in s and all start and end with "z".
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long res=0;
        // unordered_map<char, int> mp;
        long long fr=0;
        for(auto it: s){
            if(it==c) fr++;
        }
        res= fr*(fr+1)/2;
        return res;
    }
};