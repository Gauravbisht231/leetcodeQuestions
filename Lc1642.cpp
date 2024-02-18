/*
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
While moving from building i to building i+1 (0-indexed),If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

Example 1:
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    // recurison + Memoisation gives MLE
public:
int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
int n=heights.size();
int ind=0;

priority_queue<int> pq;
while(ind<n-1){
    int jump= heights[ind+1]- heights[ind];
    if(heights[ind+1]< heights[ind]) {
        ind++;
    continue;
    }
    if(bricks>=jump){
        bricks-= jump;
        pq.push(jump);
        ind++;
    }else if(ladder>0){
        if(!pq.empty() and (pq.top() > jump)){
            bricks+= pq.top();
            pq.pop();
            bricks-= jump;
            pq.push(jump);
            ladder--;
            ind++;
        }else {
            ladder--;
            ind++;
        }
    }
    else break;
}


return ind;
    }
};