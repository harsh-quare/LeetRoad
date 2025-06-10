class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<set<int>> ancts(n);
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int chd: adj[node]){
                ancts[chd].insert(node);
                for(int ancs: ancts[node]){
                    ancts[chd].insert(ancs);
                }

                indegree[chd]--;
                if(indegree[chd] == 0) q.push(chd);
            }
        }

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = vector<int>(ancts[i].begin(), ancts[i].end());
        }

        return ans;
    }
};