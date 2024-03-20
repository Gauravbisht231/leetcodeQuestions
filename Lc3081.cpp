/*
You are given a string s. s[i] is either a lowercase English letter or '?'.

For a string t having length m containing only lowercase English letters, we define the function cost(i) for an index i as the number of characters equal to t[i] that appeared before it, i.e. in the range [0, i - 1].

The value of t is the sum of cost(i) for all indices i.

For example, for the string t = "aab":

cost(0) = 0
cost(1) = 1
cost(2) = 0
Hence, the value of "aab" is 0 + 1 + 0 = 1.
Your task is to replace all occurrences of '?' in s with any lowercase English letter so that the value of s is minimized.

Return a string denoting the modified string with replaced occurrences of '?'. If there are multiple strings resulting in the minimum value, return the 
lexicographically smallest
 one.

 

Example 1:

Input:  s = "???" 

Output:  "abc" 

Explanation: In this example, we can replace the occurrences of '?' to make s equal to "abc".

For "abc", cost(0) = 0, cost(1) = 0, and cost(2) = 0.

The value of "abc" is 0.

Some other modifications of s that have a value of 0 are "cba", "abz", and, "hey".

Among all of them, we choose the lexicographically smallest.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
int getMini(vector<int> &fr){
    int ind=0;
    int mini=1e9;
    for(int i=0; i<26; i++){
        if(fr[i]<mini) {
            mini= fr[i];
            ind= i;
        }else continue;
    }
    fr[ind]= mini+1;
    return ind;
}
public:
    string minimizeStringValue(string s) {
         int n= s.size();
         string temp="";
        vector<int> fr(26, 0);
        for(auto it: s){
            if(it=='?') continue;
            else fr[it-'a']++;
        }

        for(int i=0; i<n; i++){
            if(s[i]=='?'){
                int ch= getMini(fr);
                ch= ch+97;
                temp+=ch;
            }
        }
        sort(temp.begin(), temp.end());
        int i=0, j=0;
        while(i<n){
            if(s[i]=='?'){
                s[i]= temp[j];
                i++; j++;
            }else{
                i++;
            }
        }

        return s;
    }
};

