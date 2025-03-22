class Solution {
public:
    void dfs(int nd, vector<bool>& vis, vector<vector<int>>& adj, int &sz){
        vis[nd] = true;

        for(auto it: adj[nd]){
            if(!vis[it]){
                sz++;
                dfs(it, vis, adj, sz);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // First of all, we need the number of vertices in each connected component
        vector<bool> vis(n, 0);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int sz = 1;
                dfs(i, vis, adj, sz);
                mp[i] = sz;
            }
        }

        int cnt = 0;
        // Now, we need to check if each node in a component is having the same degree as size-1
        for(auto& [nd, sz]: mp){
            // check every node
            bool valid = true;
            if(adj[nd].size() != sz-1) valid = false;
            for(auto it: adj[nd]){
                if(adj[it].size() != sz-1){
                    valid = false;
                    break;
                }
            }

            if(valid == true){
                cnt++;
            }
        }

        return cnt;
    }
};