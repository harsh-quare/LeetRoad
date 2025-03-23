class Solution {
public:
    void dfs(int nd, int dest, vector<vector<int>>& adj, int n, vector<int>& temp, vector<vector<int>>& ans){        
        if(nd == dest){
            ans.push_back(temp);
            return ;
        }

        for(auto nbr: adj[nd]){
            temp.push_back(nbr);
            dfs(nbr, dest, adj, n, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0, n-1, graph, n, temp, ans);

        return ans;
    }
};