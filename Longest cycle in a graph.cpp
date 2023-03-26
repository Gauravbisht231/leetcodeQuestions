class Solution {
private:
void dfs(vector<int> adj[], vector<int> &vis, int &node, int &res, unordered_map<int, int> &naksha){
vis[node]= true;
for(auto it: adj[node]){
    if(it!=-1 and vis[it]==0){
    naksha[it]= naksha[node]+1; // incrementing the distance after reaching the next node
    dfs(adj, vis, it, res, naksha);
    }
    else if(it!=-1 and naksha.count(it) ){
        res= max(res, naksha[node]- naksha[it]+1);
    }
}
}
public:
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        // directed graph adjacency list
        vector<int> adj[n];
        for( int i=0; i<n; i++){
            adj[i].push_back(edges[i]);
        }
        vector<int> vis(n, false);
        int res=-1;
        for(int i=0;i<n; i++){
            if(!vis[i]){
                unordered_map<int, int> naksha;
                naksha[i]= 1; // storing the distance of first node as 1
                dfs(adj, vis, i, res, naksha);
            }
        }
       
       return res;
    }
};
