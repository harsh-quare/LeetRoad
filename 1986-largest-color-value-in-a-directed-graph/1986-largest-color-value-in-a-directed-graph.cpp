class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        // step-1 create adjacency list and indegree array
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // step-2: kahn's algo, bfs; and a 2d array to maintain the max freq of each color at each node by all paths ending at each node
        vector<vector<int>> t(n, vector<int>(26, 0));
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                // this is the starting node
                // put it in queue and assign freq = 1, to its color
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0;
        int cntNodes = 0;
        // step-3: basic bfs template
        while(!q.empty()){
            int u = q.front();
            q.pop();

            cntNodes++;
            ans = max(ans, *max_element(t[u].begin(), t[u].end()));  // what is the max color value at current node

            for(auto& v: adj[u]){
                // t[v][a], t[v][b],...
                for(int col = 0; col < 26; col++){
                    t[v][col] = max(t[v][col], t[u][col] + (colors[v] - 'a' == col));
                }

                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        if(cntNodes < n) return -1;
        return ans;
    }
};