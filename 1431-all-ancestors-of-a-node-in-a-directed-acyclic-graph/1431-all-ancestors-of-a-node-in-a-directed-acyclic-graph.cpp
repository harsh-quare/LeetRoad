class Solution {
public:
    void dfs(int srcNode, int curNode, vector<vector<int>>& adj, vector<vector<int>>& ans, vector<bool> &vis){
        vis[curNode] = 1;
        for(auto chd: adj[curNode]){
            if(vis[chd]) continue;
            ans[chd].push_back(srcNode);
            dfs(srcNode, chd, adj, ans, vis);
        }

    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++){
            vector<bool> vis(n, 0);
            dfs(i, i, adj, ans, vis);
        }

        for(int i = 0; i < n; i++){
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};

// what we are doing is, starting dfs from each node, and pushing the current source node of the traversal to every node's ans encountered on the path