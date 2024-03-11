/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// one set + one resultant vector
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {      
    sort(nums1.begin(), nums1.end());   
    sort(nums2.begin(), nums2.end()); 
    int i=0, j=0;
    // if(nums1[0]==nums2[0]) res.push_back(nums1[0]);
    int n= nums1.size();
    int m= nums2.size();
    vector<int> res;
    set<int> st;
    while(i<n and j<m){
        if(nums1[i]> nums2[j]) j++;
        else if( nums1[i]< nums2[j]) i++;
        else {
            st.insert(nums1[i]);
            i++; j++;
        }
    }
    for(auto it: st) res.push_back(it);
    return res;
    }
};