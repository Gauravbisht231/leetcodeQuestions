/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

*/

#include<bits/stdc++.h>
using namespace std;


                    //                              Approach I: using vectors: TC--> O(m*N)
class Solution {
public:
int mostBooked(int n, vector<vector<int>>& meet) {

sort(meet.begin(), meet.end());
vector<long long> usedCount(n, 0);
vector<long long> curUseEnd(n, 0);
for(int i=0; i<meet.size(); i++){
    int start= meet[i][0];
    int end= meet[i][1];
    int duration = end-start;
    bool found=false;
    long long  earliestEndTime=LLONG_MAX;
    int earliestRoomAvail=0;
for(int room= 0; room<n; room++){
    if(curUseEnd[room]<=start){
        curUseEnd[room]= end;
        usedCount[room]++;
        found=true;
        break;
    }
    if(curUseEnd[room] < earliestEndTime){
        earliestEndTime= curUseEnd[room];
        earliestRoomAvail= room;
    }
    }
    // if no room ends before our End time
    if(!found){
            curUseEnd[earliestRoomAvail]+= duration;
            usedCount[earliestRoomAvail]++;
    }
}
int maxi=-1;
int room=0;
 for(int r=0; r<n; r++){
     if(usedCount[r]>maxi){
         maxi= usedCount[r];
         room= r;
     }
 }
 return room;
    }
};




                        //                  Approach II --->using priority Q: TC--> O(M*log(N))
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        int m= meet.size();
        sort(meet.begin(), meet.end());
        vector<int> mostBook(n+1, 0);
        //  availRooms--> stores empty rooms available for occupation.
        priority_queue<int, vector<int> , greater<int>> availRooms;
        // occupiedRooms---> stores pairs of {endTime, room no. Occupied} sorted according to endtimes.
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupiedRooms;
        
        for(int i=0; i<n; i++) availRooms.push(i);
        for(auto it: meet){
            auto start= it[0];
            auto end= it[1];
            auto duration= end - start;

            while(!occupiedRooms.empty() and occupiedRooms.top().first<= start){
                availRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
            if(!availRooms.empty()){
                occupiedRooms.push({end, availRooms.top()});
                mostBook[availRooms.top()]++;
                availRooms.pop();
            }else {
            // delay wala point:
            auto curEndTime= occupiedRooms.top().first;
            auto curOcRoom= occupiedRooms.top().second;
            occupiedRooms.pop();
            occupiedRooms.push({curEndTime + duration, curOcRoom});
            mostBook[curOcRoom]++;
            }

        }
        
        int maxi=-1;
        int room=-1;
        for(int r=0; r<n; r++){
            if(mostBook[r]>maxi){
                 maxi= mostBook[r];
                 room= r;
                 }
        }
return room;
    }
};