// class Solution {
//     //          RECURSIVE SOLUTION(MIGHT GIVE TLE)
//     int helper(vector<int>& days, vector<int>& costs, int n, int ind){
//                                     // base condition
//         // if the index while traversing  goes out of bound, then the fucntion can not bring anything from there, so return 0 
//     if(ind>=n) return 0; 

//                               //  else we have three routes to go with, take one day,   take                                      one week or take one month package
  
//     // to take one day voucher, we just add the cost[0] and move to the next index
//     int one= costs[0]+ helper(days, costs, n, ind+1);

//     // to take 7 or 30 day vouchers, we need to check the forward index if they are avaiable, if available, take 7 day or 30 day vouchers
//     int pointer;
//     for( pointer=ind; pointer<n and days[pointer] < days[ind]+7; pointer++ );
//      int seven=  costs[1]+ helper(days, costs, n, pointer);
//      for( pointer=ind; pointer<n and days[pointer] < days[ind]+30; pointer++ );
//     int thirty= costs[2]+ helper(days, costs, n, pointer);


// //  at the end, return minimum of all the three possibilities 
//     return min({one, seven, thirty});
//     }
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n= days.size();
        
//         // helper(days, costs, n, starting index)
//         return helper(days, costs,n, 0);
        
//     }
// };

class Solution {
                          //          MEMOISED SOLUTION TO THE RECURSIVE ONE
    int helper(vector<int>& days, vector<int>& costs, int n, int ind, vector<int> &memo){
                                    // base condition
        // if the index while traversing  goes out of bound, then the fucntion can not bring anything from there, so return 0 
    if(ind>=n) return 0; 

                              //  else we have three routes to go with, take one day,   take                                      one week or take one month package
   if(memo[ind]!=-1) return memo[ind];

    // to take one day voucher, we just add the cost[0] and move to the next index
    int one= costs[0]+ helper(days, costs, n, ind+1, memo);

    // to take 7 or 30 day vouchers, we need to check the forward index if they are avaiable, if available, take 7 day or 30 day vouchers
    int pointer;
    for( pointer=ind; pointer<n and days[pointer] < days[ind]+7; pointer++ );
     int seven=  costs[1]+ helper(days, costs, n, pointer, memo);
     for( pointer=ind; pointer<n and days[pointer] < days[ind]+30; pointer++ );
    int thirty= costs[2]+ helper(days, costs, n, pointer, memo);


//  at the end, return minimum of all the three possibilities 
    return memo[ind]= min({one, seven, thirty});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        
        vector<int> memo(n, -1);
        // helper(days, costs, n, starting index)
        return helper(days, costs,n, 0, memo);
        
    }
};
