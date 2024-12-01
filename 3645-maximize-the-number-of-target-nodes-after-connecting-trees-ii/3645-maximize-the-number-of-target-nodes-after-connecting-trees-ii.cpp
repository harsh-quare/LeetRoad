class Solution {
public:
    void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& parity){
        for(auto& nbr: adj[node]){
            if(nbr != par){
                parity[nbr] = 1 - parity[node];
                int new_parent = node;
                dfs(nbr, new_parent, adj, parity);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(auto& e: edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for(auto& e: edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        // whenever there's a talk about odd, even, means we can use the concept of parity
        // all the guys at even parity are at even distance from each other
        // all the guys at odd parity are also at even distance from each other
        // and if we want the maximum from tree2, we have 2 options, either we can take the guy having same parity as our current node, which will result in count of other parity in tree2
        // or we can take the guy with opposite parity, which will result in count of parity of tree1 node in tree2
        // means we just need any guy having most count of same parity, max(count_par2[0], count_par2[1])

        vector<int> parity1(n), parity2(m);

        dfs(0, -1, adj1, parity1);
        dfs(0, -1, adj2, parity2);

        int max_target_tree2 = max(count(parity2.begin(), parity2.end(), 0), count(parity2.begin(), parity2.end(), 1));
        int cnt0 = count(parity1.begin(), parity1.end(), 0);
        int cnt1 = count(parity1.begin(), parity1.end(), 1);

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(parity1[i] == 0){
                ans[i] = max_target_tree2 + cnt0;  //all the guys having zero parity in tree1 and maximum from tree2
            }
            else{
                ans[i] = max_target_tree2 + cnt1;
            }
        }

        return ans;
    }
};