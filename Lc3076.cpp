/*
You are given an array arr of size n consisting of non-empty strings.

Find a string array answer of size n such that:

answer[i] is the shortest 
substring
 of arr[i] that does not occur as a substring in any other string in arr. If multiple such substrings exist, answer[i] should be the 
lexicographically smallest
. And if no such substring exists, answer[i] should be an empty string.
Return the array answer.

 

Example 1:

Input: arr = ["cab","ad","bad","c"]
Output: ["ab","","ba",""]
Explanation: We have the following:
- For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
- For the string "ad", there is no substring that does not occur in any other string.
- For the string "bad", the shortest substring that does not occur in any other string is "ba".
- For the string "c", there is no substring that does not occur in any other string.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {

    // res[i] has priority while filling: 
    // 1. smallest honi chaiye length wise
    // 2. if same size ki smallest hai, to lexicographically check karo 
    void removeCommon(set<string> &st,vector<string>& arr, int ind ){

        for(int i=0; i<arr.size(); i++){
            if(i==ind) continue;
            string cur= arr[i];
            for(int j=0; j<arr[i].size(); j++){
                string sub="";
                    for(int k=j; k<arr[i].size(); k++){
                        sub+= cur[k];
                        if(st.find(sub)!= st.end()) st.erase(sub);
                        else continue;
                }
            }
        }
        return;
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n= arr.size();
        vector<string> res(n, "");
        for(int i=0; i<n; i++){
            // map<string, int> mp;
            set<string> st;
            string cur= arr[i];
            int len= cur.size();

            for(int j=0; j<len; j++){
            string sub="";
                for(int k=j; k<len; k++){
                    sub+= cur[k];
                   st.insert(sub);
                }
            }
            // yaha tak map bhar chuka hai: arr[i]  ke liye :-)
            // remove common substrings:
            removeCommon(st, arr, i);
            //after removing
            string lexiSmallestUncommon="";
            int sz= 1e9;
            if(st.empty()) continue;
            for(auto it: st){
                if(it.size()<sz) {
                    sz= it.size();
                    lexiSmallestUncommon= it;
                }
                
            }
            res[i]= lexiSmallestUncommon;
        }


        return res;
    }
};