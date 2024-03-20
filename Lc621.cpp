/*
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count=0;
        vector<int> fr(26, 0);
        priority_queue<int> q;
        for(auto it: tasks){
            fr[it-'A']++;
        }
        for(auto it: fr){
            if(it>0)q.push(it);
        }

        while(!q.empty()){
            int cycle = n+1; // elements after repeat (for n=1) "A-B"-A
            vector<int> cur;
            while(!q.empty() and cycle){
                int topFr= q.top();
                q.pop();
                cur.push_back(topFr);
                cycle--;
            }
            for(auto it: cur){
                if(it-1>0) q.push(it-1);
                }
            if(q.empty()) count+= cur.size();
            else count+= n+1;
        }


        return count;
    }
};