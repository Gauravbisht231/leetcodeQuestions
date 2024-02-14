/*

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> pos, neg;
      vector<int> res;
      for(auto it: nums){
            if(it>=0) pos.push_back(it); 
            else neg.push_back(it);
      }  
      int i=0, j=0;
      int n, m;
      n= pos.size();
      m= neg.size();
      while(i<pos.size() or j<neg.size()){
          if(i<n)res.push_back(pos[i++]);
         if(j<m) res.push_back(neg[j++]);
      }
      while(i<n) res.push_back(pos[i++]);
      while(j<n) res.push_back(pos[j++]);
      return res;
    }
};