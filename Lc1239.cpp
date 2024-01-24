#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
bool isOk(string a, string b){
    set<char> st;
    for(auto it: a){
        if(st.find(it)!= st.end()) return 0;
        st.insert(it);
    }
    for(auto it: b){
        if(st.find(it)!= st.end()) return 0;
        continue;
    }
    return 1;
}
int helper(int ind, string res, vector<string> &arr, int n){
    if(ind>=n) return res.size();
    int take=0, nottake=0;
    if(!isOk(arr[ind], res)){
        nottake= helper(ind+1, res, arr, n);
    }else{
        take= helper(ind+1, res, arr, n);
        nottake= helper(ind+1, res + arr[ind], arr, n);
    }
    return max(take, nottake);
}
public:
    int maxLength(vector<string>& arr) {
    string res="";
    int ind=0;
    int n= arr.size();
    return helper(ind, res, arr, n);
    }
};