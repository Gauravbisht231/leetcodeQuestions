#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n= nums.size();
        int totalsum=0;
        int actualSum= n*(n+1)/2;
        for(auto it: nums){
                mp[it]++;
              totalsum+=it;  

        }
        int repeating=INT_MIN, missing=0;
        for(auto it: mp){
         
            if(it.second >1) repeating= it.first;
        }
        totalsum-= repeating;
        missing= actualSum-totalsum;

        return {repeating, missing};
    }
};