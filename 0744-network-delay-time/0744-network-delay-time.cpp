class Solution {
public:
    using pii = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adj list
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n+1, INT_MAX);  // mark all the nodes as unreachable from given node 'k'.
        dist[k] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int curTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &[nbr, time]: adj[node]){
                // only update if you got better distance for neighbor node 
                if(dist[nbr] > curTime + time){
                    dist[nbr] = curTime + time;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int maxi = INT_MIN;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};