class Solution {
public:
bool pathHelper(int src,int dest,vector<bool>&vis,vector<vector<int>>&adj){
    //BaseCase
    if(src==dest) return true;
    vis[src]=true;
    
    for(int v: adj[src]){
        if(!vis[v]){
            if(pathHelper(v,dest,vis,adj)){
                return true;
            }
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

        }
        vector<bool>vis(n,false);
        return pathHelper(source,destination,vis,adj);
            
    }
};