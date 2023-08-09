class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod= 1e9+7;
    vector<pair<long long, long long>> adj[n+1];
    for(auto it: roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
vector<long long> ways(n, 0);
vector<long long> time(n, LONG_MAX);
time[0]=0;
ways[0]=1;

priority_queue< pair<long long, long long> , vector<pair<long long, long long>> , greater<pair<long long, long long>> >koo;
koo.push({0,0});

while(!koo.empty()){
    auto top= koo.top();
    long long curtime= top.first;
    long long node= top.second;
    koo.pop();
    for(auto it: adj[node]){
        long long adjnode= it.first;
        long long nextime= it.second;
        // first time visiting a node, with min distance from 0 to this node
        if(time[adjnode]> curtime + nextime){
            time[adjnode]= curtime + nextime;
            ways[adjnode]= ways[node]%mod;
            koo.push({time[adjnode], adjnode});
        }
        // visiting again to this node with min distance, from 0 
        else if(time[adjnode]== curtime + nextime){
            ways[adjnode]= (ways[adjnode]+ ways[node])%mod;
        }
    }
}
return ways[n-1]% mod;

    }
};
