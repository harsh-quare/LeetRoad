class Solution {
public:
    #define pii pair<int, int> 
    //dist, nbr-node
    unordered_map<int, vector<pii>> adj; //O(V+E)

    int dijkstra(int n){
        vector<int> dist(n, INT_MAX);
        //single source to all nodes shortest dist
        //here: 0 --> n-1

        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});  //dist, node

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1) return dist[n-1];  //iske baad isse shorter value nhi milegi gue to priority_queue nature

            for(auto& p: adj[node]){
                int nbrNode = p.second;
                int wt = p.first;

                if(dist[nbrNode] > d + wt){
                    dist[nbrNode] = d + wt;
                    pq.push({d + wt, nbrNode});
                }
            }
        }

        return dist[n-1];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        for(int i = 0; i<n-1; i++){
            adj[i].push_back({1, i+1});  //each edge weight is 1
        }

        vector<int> ans;

        for(auto& q: queries){
            int u = q[0];
            int v = q[1];

            adj[u].push_back({1, v});
            ans.push_back(dijkstra(n));
        }

        return ans;
    }
};