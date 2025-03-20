class Solution {
public:
    void dfs(int nd, vector<int>& vis, vector<vector<pair<int,int>>> &adj, unordered_map<int, int>& nodeComp, int comp, int &cmpWt){
        vis[nd] = 1;
        nodeComp[nd] = comp;

        for(auto [it, wt]: adj[nd]){
            cmpWt &= wt;
            if(!vis[it]){
                dfs(it, vis, adj, nodeComp, comp, cmpWt);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        unordered_map<int, int> nodeComp;  // node -> its component number
        unordered_map<int, int> compWt;  // component number and its weight

        int comp = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int cmpWt = INT_MAX;
                dfs(i, vis, adj, nodeComp, comp, cmpWt);
                compWt[comp] = cmpWt;
                comp++;
            }
        }

        vector<int> ans;
        for(auto q: query){
            int s = q[0];
            int e = q[1];

            if(nodeComp[s] == nodeComp[e]){
                ans.push_back(compWt[nodeComp[s]]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// The thing to notice here is that, I need to minimize the cost of a path between two nodes.
// And the cost is defined as the AND of all the weights in the path.
// Acc to the property of AND, we always get the number smaller or equal after applying AND
// Means, to minimize the cost of the path, we would try to take as many weights possible to increase the chances of reducing the nett cost of the path.
// We would first check if the two nodes are reachable to each other or not, and if yes, then the answer would be the AND of that component's AND of all weights, else it will be -1