class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n == 1) return 1;

        vector<vector<int>> adj(n);
        vector<long long> nodeVals(values.begin(), values.end());
        vector<int> degree(n);

        for(auto& it: edges){
            int u = it[0], v = it[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        int compCnt = 0;

        for(int i = 0; i < n; i++){
            if(degree[i] == 1) q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            degree[cur]--;

            long long addVal = (nodeVals[cur] % k == 0) ? 0 : nodeVals[cur];

            if(addVal == 0) compCnt++;

            for(auto& nbr: adj[cur]){
                if(degree[nbr] > 0){
                    degree[nbr]--;
                    nodeVals[nbr] += addVal;

                    if(degree[nbr] == 1) q.push(nbr);
                }
            }
        }

        return compCnt;
    }
};