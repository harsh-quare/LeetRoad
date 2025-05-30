class Solution {
public:
    vector<int> bfs(int stNode, vector<vector<int>>& adj){
        queue<int> q;
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, 0);

        q.push(stNode);
        dist[stNode] = 0;
        vis[stNode] = 1;

        while(!q.empty()){
            int nd = q.front();
            q.pop();

            for(auto& nbr: adj[nd]){
                if(!vis[nbr]){
                    vis[nbr] = 1;
                    q.push(nbr);
                }
                dist[nbr] = min(dist[nbr], dist[nd] + 1);
            }
        }

        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        
        vector<int> dist1 = bfs(node1, adj);
        vector<int> dist2 = bfs(node2, adj);

        // for(int i = 0; i < n; i++){
        //     cout << dist1[i] << ", " << dist2[i] << endl;
        // }

        int maxDist = INT_MAX;  // I need to minimize this maxDist
        int smallestNode = -1;

        for(int i = 0; i < n; i++){
            int curMaxi = max(dist1[i], dist2[i]);

            if(curMaxi < maxDist){
                maxDist = curMaxi;
                smallestNode = i;
            }
        }

        return smallestNode;
    }
};