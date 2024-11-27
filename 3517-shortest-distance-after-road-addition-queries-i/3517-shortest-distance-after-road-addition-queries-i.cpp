class Solution {
public:
    int bfs(int n, vector<vector<int>>& adj){
        vector<bool> vis(n, false);
        vis[0] = true;
        queue<int> q;
        q.push(0);      
        
        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front();
                q.pop();

                if(cur == n-1){  //reached destination
                    return level;
                }

                for(auto& nbr: adj[cur]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<n-1; i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans;

        for(auto& q: queries){
            int u = q[0];
            int v = q[1];

            adj[u].push_back(v);
            ans.push_back(bfs(n, adj));
        }

        return ans;
    }
};