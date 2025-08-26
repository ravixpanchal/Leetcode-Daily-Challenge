class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int>ans;
        queue<int>q;
        vector<bool>vis(n,false);
        
        q.push(0);
        vis[0]=true;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            
            for(int v: adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        
        return ans;
        
        
    }
};