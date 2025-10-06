class DSU{
    vector<int> par, size;
public:
    DSU(int n){
        par.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i <= n; i++) par[i] = i;
    }

    int findParent(int node){
        if(par[node] == node) return node;

        return par[node] = findParent(par[node]);
    }

    void unionBySize(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u == par_v) return ;

        if(size[par_u] > size[par_v]){
            par[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            par[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int targetCell = (n-1)*n + (n-1);
        DSU ds(n * n);

        vector<tuple<int, int, int>> edges;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                edges.push_back({grid[i][j], i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<bool> vis(n*n, 0);

        vector<int> dirx = {-1, 0, 1, 0, -1};
        for(auto &[height, row, col]: edges){
            int cell = row*n + col;

            vis[cell] = 1;  // "reachable by swimming"

            for(int i = 0; i < 4; i++){
                int nrow = row + dirx[i];
                int ncol = col + dirx[i+1];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    int nbr = nrow*n + ncol;
                    if(vis[nbr]){
                        ds.unionBySize(cell, nbr);
                    }
                }
            }

            // check if start and end are connected
            if(ds.findParent(0) == ds.findParent(targetCell)){
                return height; // min water level found
            }
        }

        return -1;
    }
};