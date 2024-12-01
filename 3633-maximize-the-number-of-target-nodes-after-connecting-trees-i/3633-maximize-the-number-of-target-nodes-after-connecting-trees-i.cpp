class Solution {
public:
    int dfs(int node, int par, vector<vector<int>>& adj, int k){
        // number of nodes in subtree of u, that are at distance at max k from u
        if(k < 0) return 0;

        int res = 1;
        for(int nbr: adj[node]){
            if(nbr != par){
                int new_parent = node;
                res += dfs(nbr, new_parent, adj, k-1);
            }
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(int i = 0; i < n-1; i++){
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }

        for(int i = 0; i < m-1; i++){
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        int max_target_tree2 = 0;  //tree2 me se jo k-1 distance wale maximum number of guys leke betha h, vahi hame chahiye
        for(int i = 0; i < m; i++){
            max_target_tree2 = max(max_target_tree2, dfs(i, -1, adj2, k-1));
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            //calculate number of nodes at dist at max k in tree1 and add this to the node in tree2 which is having most number of nodes having dist at max k
            ans[i] = dfs(i, -1, adj1, k) + max_target_tree2;
        }

        return ans;
    }
};
