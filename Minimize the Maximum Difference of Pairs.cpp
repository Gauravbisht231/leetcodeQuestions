class Solution {
private:
bool areEnoughPairs(vector<int> &nums, int diff, int p){
    int counter=0;
    int i=0;
    while(i<nums.size()-1){
        if(nums[i+1]-nums[i]<=diff){
            counter++;
            i+=2;
        }
        else i++;
    }
    return counter>=p;
}
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int lo=0;
        int hi= nums[n-1]-nums[0];
        int res= 1e9+1;
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(areEnoughPairs(nums, mid, p)){
                res= mid;
                hi= mid-1;
            }
            else{
                lo= mid+1;
            }
        }
        return res;
    }
};
