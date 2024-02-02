/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
Example 1:
Input: low = 100, high = 300
Output: [123,234]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int lo, int hi){
         vector<int> res;
         queue<int> koo;
        for(int i=1; i<=8; i++){
            koo.push(i);
        }
        while(!koo.empty()){
            int top= koo.front();
            koo.pop();
            if(top>hi) break;
            if(top>=lo and top<=hi) res.push_back(top);
            auto lastDigit= top%10;
            if(lastDigit<=8){
            top= top*10 + lastDigit +1 ;
            koo.push(top);
            }
        }
        return res;
    }
};