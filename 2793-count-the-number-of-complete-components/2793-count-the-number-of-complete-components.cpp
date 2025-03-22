class Solution {
public:
    void dfs(int nd, vector<bool>& vis, vector<vector<int>>& adj, int &nodes, int &egs){
        nodes++;
        egs += adj[nd].size();  // adding edges from current vertex
        vis[nd] = true;

        for(auto it: adj[nd]){
            if(!vis[it]){
                dfs(it, vis, adj, nodes, egs);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // First of all, we need the number of vertices in each connected component, and the number of edges too
        vector<bool> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int nodes = 0;
                int egs = 0;
                dfs(i, vis, adj, nodes, egs);

                cout << nodes << " " << egs << endl;

                egs /= 2;  // all the edgee were counted twice, because the graph is undirected
                
                if(egs == nodes*(nodes-1)/2){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};