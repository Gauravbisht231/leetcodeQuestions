/*
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

 

Example 1:

Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string maximumOddBinaryNumber(string s) {
      int n= s.size();
      int cntOne= count(s.begin(), s.end(),'1');
      s[n-1]='1';
      cntOne--;
      for(int i=0; i<n-1; i++){
          if(cntOne>0){
              s[i]='1';
              cntOne--;
          }else s[i]='0';
      }  
      return s;
    }
};