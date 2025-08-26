class Solution {
  public:
  void dfsHelper(int u, vector<bool>&vis,vector<vector<int>>& adj,vector<int>&ans){
      vis[u]=true;
      ans.push_back(u);
      for(int v: adj[u] ){
          if(!vis[v]){
              dfsHelper(v,vis,adj,ans);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>ans;
        vector<bool>vis(n,false);
        dfsHelper(0,vis,adj,ans);
        return ans;    
    }
};