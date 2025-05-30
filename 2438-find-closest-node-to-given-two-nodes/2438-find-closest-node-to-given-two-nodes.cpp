class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<int>& vis){
        vis[node] = 1;

        int nbr = edges[node];
        if(nbr != -1 && !vis[nbr]){
            vis[nbr] = 1;
            dist[nbr] = dist[node] + 1;
            dfs(nbr, edges, dist, vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX), vis1(n, 0);
        vector<int> dist2(n, INT_MAX), vis2(n, 0);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1, edges, dist1, vis1);
        dfs(node2, edges, dist2, vis2);

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