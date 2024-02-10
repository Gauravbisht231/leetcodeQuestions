/*
Shortest Common Supersequence 
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string shortestCommonSupersequence(string s, string t) {
int n= s.size();
int m= t.size();
string super="";
vector<vector<int>> dp(n+1, vector<int> (m+1 , 0));
for(int i=n-1; i>=0; i--){
    for(int j=m-1; j>=0; j--){
        int take=0, nottake=0;
        if(s[i]==t[j]) take= 1 + dp[i+1][j+1];
        else nottake= (max(dp[i+1][j], dp[i][j+1]));
        dp[i][j]= max(take, nottake);
    }
}
cout<<dp[0][0]<<endl;

int i=0, j=0;
while(i<n and j<m){
	if(s[i]==t[j]){
		super+= s[i];
		j++;
		i++;
	}else{
		if(dp[i+1][j]>= dp[i][j+1]){
			super+= s[i];
			i++;
		}else {
			
			super+= t[j];
			j++;
		}
	
	}

}
        while(i<n){
        super+= s[i];
        i++;
        }
        while(j<m){
        super+= t[j];
        j++;
        }
	return super;
    }
};