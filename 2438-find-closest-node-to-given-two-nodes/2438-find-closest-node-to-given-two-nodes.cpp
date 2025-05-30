class Solution {
public:
    void bfs(int stNode, vector<int>& edges, vector<int>& dist){
        queue<int> q;
        int n = edges.size();

        q.push(stNode);
        dist[stNode] = 0;
        vector<bool> vis(n, 0);
        vis[stNode] = 1;

        while(!q.empty()){
            int nd = q.front();
            q.pop();

            int nbr = edges[nd];
            if(nbr != -1 && !vis[nbr]){
                q.push(nbr);
                vis[nbr] = 1;
                dist[nbr] = dist[nd] + 1;
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

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