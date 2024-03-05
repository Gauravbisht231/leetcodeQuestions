/*
Question: Minimum Length of String After Deleting Similar Ends
statement: Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).

Example:
Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int n= s.size();
        int lo=0, hi= n-1;
        while(lo<hi){
            if(s[lo]!= s[hi]) break;
            else {
                while(s[lo]==s[lo+1] and lo<hi) lo++;
                while(s[hi]==s[hi-1] and hi>lo) hi--;
                lo++;
                hi--;
            }
        }
        int res= hi-lo+1;
        return res>0?res:0;
    }
};