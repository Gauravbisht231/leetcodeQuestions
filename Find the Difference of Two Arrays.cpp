class Solution {
    // bit complex to understand--->BRUTE FORCE
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res; // O(n+m) max space
        set<int> one; //o(N)
        set<int> two; //O(M)
        for(auto it:nums1)
            one.insert(it);
        
        for(auto it: nums2)
            two.insert(it);

            vector<int> dummy; // ~O(N) space
            for(auto it: one){
                if(two.find(it)==two.end())
                 dummy.push_back(it); 
            }
            res.push_back(dummy);
            dummy.clear();
            for(auto it: two){
                if(one.find(it)== one.end()) 
                dummy.push_back(it);
            }
            res.push_back(dummy);
            return res;
            // O(NlogN) time complexity
    }
};
