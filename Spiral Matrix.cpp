class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        int startro=0, startcol=0, endro=n-1, endcol=m-1;
        int count=0;
        int total=n*m;
        vector<int> res;
        while(count<total){ 
for(int ind= startcol; count<total and ind<=endcol; ind++)
{
    // left to right
res.push_back(mat[startro][ind]);

count++;
}startro++;

for(int ind=startro; count<total and ind<=endro; ind++){
    // top to bottom 
res.push_back(mat[ind][endcol]);
count++;
}
endcol--;

for(int ind=endcol; count<total and ind>=startcol; ind--){
    // left to right
    res.push_back(mat[endro][ind]);
    count++;
}   endro--;

for(int ind=endro; count<total and ind>=startro; ind--){
    res.push_back(mat[ind][startcol]);
  
    count++;
}  startcol++;
        }
        return res;
    }
};
