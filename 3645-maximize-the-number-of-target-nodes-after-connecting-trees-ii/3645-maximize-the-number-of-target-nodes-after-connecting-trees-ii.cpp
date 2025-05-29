class Solution {
public:
    void dfs(vector<vector<int>>& adj, unordered_set<int>& evens, int node, bool isOdd, vector<bool>& vis){
        vis[node] = 1;

        if(isOdd == false){
            evens.insert(node);
        }

        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                dfs(adj, evens, nbr, !isOdd, vis);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Its fu*king easy man.
        // We just need to know about which nodes are at even position and which are at odd position
        // I will take a starting point, start my dfs from there, and store all nodes at even distance in even set, and odd ones in odd set. It will help me get the set of each node and then I can tell by the sixe of the set, how many nodes in tree1 are reachable at even distance
        // Now if I have to connect one node from t1 to any node in t2.
        // So, we will try to get the maximum of (odd.size(), evens.size()) from t2, and take that to add in my t1's ans

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

        unordered_set<int> evensT1;
        vector<bool> vis1(n, 0);
        dfs(adj1, evensT1, 0, 0, vis1);  // first 0 is starting node, second 0 is the flag which indicates even distance or odd distance

        unordered_set<int> evensT2;
        vector<bool> vis2(m, 0);
        dfs(adj2, evensT2, 0, 0, vis2);

        int bestFromT2 = max(evensT2.size(), m - evensT2.size());

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(evensT1.find(i) != evensT1.end()){
                ans[i] = evensT1.size() + bestFromT2;
            }
            else{
                ans[i] = (n - evensT1.size()) + bestFromT2;
            }
        }

        return ans;

    }
};