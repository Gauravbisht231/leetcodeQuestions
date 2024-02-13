/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.
Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool check(string &s){
    int i=0;
    int j= s.size()-1;
    while(i<=j) {
        if(s[i]==s[j])
        {
            i++; j--;
        }
        else return false;
    }
    return true;
}
string firstPalindrome(vector<string>& words) {

    int n= words.size();
    for(auto word: words){
        if(check(word)==true) return word;
    }    
    return "";
    }
};