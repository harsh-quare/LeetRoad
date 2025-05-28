class Solution {
public:
    void dfs(int nd, vector<vector<int>>& adj, int cap, int& cnt, vector<int>& vis){
        if(cap <= 0){
            return ;
        }

        vis[nd] = 1;

        for(auto& nbr: adj[nd]){
            if(!vis[nbr]){
                cnt++;
                dfs(nbr, adj, cap-1, cnt, vis);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // I need to know number of nodes I can reach from each node in tree2 with power of k-1 => using bfs?
        // I need to know number of nodes I can reach from each node in tree1 with power of k => using bfs?

        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(auto& it: edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for(auto& it: edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int maxiFromT2 = 1;
        for(int i = 0; i < m; i++){
            
            if(k == 0){
                maxiFromT2 = 0;
                break;
            } 

            int cnt = 1;
            vector<int> vis(m, 0);
            dfs(i, adj2, k-1, cnt, vis);
            maxiFromT2 = max(maxiFromT2, cnt);
        }

        // cout << maxiFromT2 << endl;

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int cnt = 1;
            vector<int> vis(n, 0);
            dfs(i, adj1, k, cnt, vis);
            ans[i] = cnt + maxiFromT2;
        }

        return ans;
    }
};