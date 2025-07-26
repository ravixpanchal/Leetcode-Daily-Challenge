class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int total = 0;
        for (int x : nums) total ^= x;
        
        vector<int> sub(n);
        vector<int> in(n), out(n);
        int timer = 0;
        
        function<void(int, int)> dfs = [&](int u, int p) {
            in[u] = timer++;
            sub[u] = nums[u];
            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                    sub[u] ^= sub[v];
                }
            }
            out[u] = timer;
        };
        
        dfs(0, -1);
        
        auto isAncestor = [&](int u, int v) {
            return in[u] <= in[v] && out[v] <= out[u];
        };
        
        int ans = INT_MAX;
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (i == j) continue;
                
                int a, b, c;
                
                if (isAncestor(i, j)) {
                    a = sub[j];
                    b = sub[i] ^ sub[j];
                    c = total ^ sub[i];
                } else if (isAncestor(j, i)) {
                    a = sub[i];
                    b = sub[j] ^ sub[i];
                    c = total ^ sub[j];
                } else {
                    a = sub[i];
                    b = sub[j];
                    c = total ^ sub[i] ^ sub[j];
                }
                
                int mx = max({a, b, c});
                int mn = min({a, b, c});
                ans = min(ans, mx - mn);
            }
        }
        
        return ans;
    }
};