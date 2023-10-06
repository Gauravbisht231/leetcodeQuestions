#include<bits/stdc++.h>
// problem statement:  Given an integer value, break it  into sum of 'k' positive integres where,k>=2, and maximize the product of those integres
using namespace std;
class Solution{

public: 
int IntegerBreak(int n){
if(n<4) return n-1;
int res=1;
while(n>4){
   n= n-3;
   res=res*3;
}
res= res*n;
return res;
}
};


int main(){

    int n;
    cin>>n;
    Solution obj1;
    cout<<obj1.IntegerBreak(n);
   
    return 0;
}