/*
You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

 

Example 1:

Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& c) {
       int totalAppil= accumulate(apple.begin(), apple.end(), 0);
       sort(c.rbegin(), c.rend());
       int carton=0;
       int n= c.size();
       int i=0;
       while(totalAppil>0 and i<n){
            int curCapacity= c[i];
            totalAppil-= curCapacity;
            i++;
            carton++;
       } 
       return carton;
    }
};