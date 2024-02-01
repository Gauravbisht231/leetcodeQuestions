#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> divideArray(vector<int>& nums, int k) {
vector<vector<int>> res;
sort(nums.begin(), nums.end());
int n= nums.size();
for(int i=0; i<n-2; i+=3){
 
    if(nums[i+2]- nums[i] <= k) {
        res.push_back({nums[i], nums[i+1], nums[i+2]});
    }
    else return {};
}
return res;
    }
};