class Solution {
public:
    double average(vector<int>& s) {
    double res=0;
int mini= 1e6;
int maxi= 0;
int n= s.size();

for(int i=0; i<n; i++){
        mini= min(mini, s[i]);
        maxi= max(maxi, s[i]);
        res+= s[i];
}
res= res- mini- maxi;
res= double(res)/(n-2);
return res;
// O(N) approach
    }
};
