class Solution {
public:
    void dfs(int node, int par, vector<int>& xorSubtree, vector<int>& inTime, vector<int>& outTime, int &timer, vector<int>& nums, vector<vector<int>>& adj){
        xorSubtree[node] = nums[node];
        inTime[node] = timer;
        timer++;

        for(int &nbr: adj[node]){
            if(nbr != par){
                dfs(nbr, node, xorSubtree, inTime, outTime, timer, nums, adj);
                xorSubtree[node] ^= xorSubtree[nbr];
            }
        }

        outTime[node] = timer;
        timer++;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime){
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    int getScore(int a, int b, int c){
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});

        return maxXor - minXor;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();  // no. of nodes

        vector<vector<int>> adj(n);
        for(auto& edg: edges){
            int u = edg[0], v = edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // I will treat any one node as root node
        // and try all n^2 pairs of nodes, from which one of their edges will be removed

        vector<int> xorSubtree(n, 0); //precompute xor for all subtrees

        vector<int> inTime(n, 0), outTime(n, 0); // for checking if a node is ancestor of another node => means if they are in same subtree or not
        int timer = 0;

        // root => 0
        dfs(0, -1, xorSubtree, inTime, outTime, timer, nums, adj);

        // all possible pairs of nodes
        int ans = INT_MAX;
        for(int u = 1; u < n; u++){     // 0 is root node, no need to include that
            for(int v = u+1; v < n; v++){
                int xor1;
                int xor2;
                int xor3;

                if(isAncestor(u, v, inTime, outTime)){
                    xor1 = xorSubtree[v];
                    xor2 = xorSubtree[u] ^ xorSubtree[v];
                    xor3 = xorSubtree[0] ^ xor1 ^ xor2;
                }
                else if(isAncestor(v, u, inTime, outTime)){
                    xor1 = xorSubtree[u];
                    xor2 = xorSubtree[v] ^ xorSubtree[u];
                    xor3 = xorSubtree[0] ^ xor1 ^ xor2;
                }
                else{
                    xor1 = xorSubtree[u];
                    xor2 = xorSubtree[v];
                    xor3 = xorSubtree[0] ^ xor1 ^ xor2;
                }

                ans = min(ans, getScore(xor1, xor2, xor3));
            }
        }
        return ans;
    }
};