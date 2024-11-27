class Solution {
public:
    int bfs(int st, int end, int n, vector<int> adj[n]){
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        dist[st] = 0;
        q.push(st);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(auto& next: adj[cur]){
                if(dist[next] > dist[cur] + 1){
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
        return dist[end];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(int i = 0; i<n-1; i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans;

        for(auto& q: queries){
            int u = q[0];
            int v = q[1];

            adj[u].push_back(v);
            ans.push_back(bfs(0, n-1, n, adj));
        }

        return ans;
    }
};