class Solution {
private:
bool isok(vector<int> &nums, int mid, int n){
   vector<long long> dummy(nums.begin(), nums.end());
    for(int i=0; i<n-1; i++){
            if(dummy[i]>mid){
                return false;
            }
            else{
                long long diff= mid- dummy[i];
                dummy[i+1]= dummy[i+1] - diff;

            }
    }
    return dummy[n-1]<=mid;
}
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n= nums.size();
        int res=0;
        int left=0;
int right= *max_element(nums.begin(), nums.end());
while(left<=right){
  auto  mid= left + (right-left)/2;
    if(isok(nums, mid, n)){
        res=mid;
        right= mid-1;
    }
    else {
        left= mid+1;
    }
}
return res;

    }
};
