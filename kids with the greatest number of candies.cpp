class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int more) {
       int n=  c.size();
       vector<bool> res(n, false);
       for(int i=0; i<n; i++){
            int cur= c[i]+ more;
for(int j=0; j<n; j++){
if(cur<c[j]) break;
else{
    if(j==n-1) res[i]= true;
}

}

       }
       return res;
    }
};
