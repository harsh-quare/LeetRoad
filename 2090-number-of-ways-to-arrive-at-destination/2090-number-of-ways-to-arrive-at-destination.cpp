class Solution {
public:
    #define pii pair<long long, int>
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& r: roads){
            int u = r[0];
            int v = r[1];
            int t = r[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> pathCost(n, LLONG_MAX);
        vector<int> waysCnt(n, 0);

        pathCost[0] = 0;
        waysCnt[0] = 1;  // one way to reach from 0 to 0

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});  // currenctCost, currentNode

        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();

            for(auto& [nbr, wt]: adj[node]){

                if(cost + wt < pathCost[nbr]){
                    pathCost[nbr] = cost + wt;
                    waysCnt[nbr] = waysCnt[node];        // to reach this node, there will be same number of ways as the node from where you are coming
                    pq.push({pathCost[nbr], nbr});
                }
                else if(cost + wt == pathCost[nbr]){  // when you get a path having the same minimum cost, add the number of ways from previous nodes, these ways are additional from what you have already got from other paths.
                    waysCnt[nbr] = (waysCnt[nbr] + waysCnt[node]) % mod;
                }
            }
        }

        return waysCnt[n-1];
    }
};