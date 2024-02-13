/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

//                      This is not the most efficient way to solve this problem, will uplaod later ;)
    int countSubstrings(string s) {
       int counter=0;
       int n= s.size();
       for(int i=0; i<n; i++){
           for(int j=i; j<n; j++){
                int len= j-i+1;
                string sub= s.substr(i, len);
                string revSub= sub;
                reverse(revSub.begin(), revSub.end());
                if(sub== revSub) counter++;
           }
       }
       return counter; 
    }
};