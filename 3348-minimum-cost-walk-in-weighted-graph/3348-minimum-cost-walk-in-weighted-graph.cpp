class DSU{
public:
    vector<int> par;
    vector<int> dist;
    vector<int> rank;

    DSU(int n){
        dist.resize(n+1, INT_MAX);
        par.resize(n+1, 0);
        rank.resize(n, 0);

        for(int i = 0; i <= n; i++){  // initialize each node's parent as itself
            par[i] = i;
        }
    }

    int findPar(int u){
        if(par[u] == u){
            return par[u];
        }
        return findPar(par[u]);
    }

    void unionFind(int u, int v, int val){
        int parU = findPar(u);
        int parV = findPar(v);

        if(rank[parU] < rank[parV]){
            par[parU] = parV;
            // dist[parU] = dist[parU] & val;
        }
        else if(rank[parU] > rank[parV]){
            par[parV] = parU;
            // dist[parV] = dist[parV] & val;
        }
        else{
            par[parV] = parU;
            rank[parU]++;
            // dist[parU] = dist[parU] & val;
        }

        dist[parU] = dist[parV] = dist[parU] & dist[parV] & val;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU ds(n);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            ds.unionFind(u, v, w);
        }

        vector<int> ans;
        for(int i = 0; i < query.size(); i++){
            int s = query[i][0];
            int t = query[i][1];

            int parU = ds.findPar(s);
            int parV = ds.findPar(t);

            if(parU == parV) ans.push_back(ds.dist[parV]);
            else ans.push_back(-1);
        }

        return ans;
    }
};