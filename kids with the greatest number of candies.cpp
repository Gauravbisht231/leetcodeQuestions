class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int more) {
        int n= c.size();
        int maxi= *max_element(c.begin(), c.end());
        vector<bool> res(n, false);
        for(int i=0; i<n; i++){
            int cur= c[i]+ more;
            if(cur>=maxi) res[i]= true;
            else continue;
        }
        return res;
    }
}; 
