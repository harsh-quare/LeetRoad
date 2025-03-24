class Solution {
public:
    int intersect(vector<int>& a, vector<int>& b){
        // Count number of distinct integers common to both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        int cnt = 0;

        while(i < n && j < m){
            if(a[i] < b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            else{  //(a[i] == b[j])
                cnt++;
                int val = a[i];
                while(i < n && a[i] == val) i++;
                while(j < m && b[j] == val) j++;
            }
        }

        return cnt;
    }
    void dfs(int nd, vector<vector<int>>& adj, vector<bool>& vis){
        vis[nd] = true;

        for(auto nbr: adj[nd]){
            if(!vis[nbr]){
                dfs(nbr, adj, vis);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(intersect(properties[i], properties[j]) >= k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Now, count connected components
        vector<bool> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};