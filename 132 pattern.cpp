class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        
        // O(N3) approach
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                        if((nums[i]< nums[k] ) and (nums[k]< nums[j]))return true;
                }
            }
        }

        return false;
    }
};
