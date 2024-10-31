class Solution {
public:
    int ans = -1;
    void dfs(int u, vector<int>& edges, vector<bool>& vis, vector<bool>& inRecursion, vector<int>& dist){
        if(u != -1){  //only when there is an edge present
            vis[u] = true;
            inRecursion[u] = true;

            int v = edges[u];
            if(v != -1 && !vis[v]){
                vis[v] = true;
                dist[v] = dist[u] + 1;
                dfs(v, edges, vis, inRecursion, dist);
            }
            else if(v != -1 && inRecursion[v] == true){ //cycle hai but inRecursion wala true hona chahiye{
                ans = max(ans, dist[u] - dist[v] + 1);
            }

            inRecursion[u] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, 0);
        vector<bool> inRecursion(n, 0);
        vector<int> dist(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, edges, vis, inRecursion, dist);
            }
        }

        return ans;
    }
};