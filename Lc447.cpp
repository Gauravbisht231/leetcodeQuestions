/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

 

Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: 2
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int boom=0;
        int n= points.size();
        for(int i=0; i<n; i++){
            unordered_map<int, int> mp;
            // mp<dist, fr> b/w point i & j
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int a= points[i][0], b= points[i][1], x= points[j][0], y= points[j][1];
                int dist= (x-a)*(x-a) + (y-b)*(y-b);
                mp[dist]++;
            }

            for(auto it: mp){
                if(it.second>=2){
                    boom+= (it.second)*(it.second-1);
                }
            }
        }

        return boom;
    }
};