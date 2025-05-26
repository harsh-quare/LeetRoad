class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<vector<int>> nodeColor(n, vector<int>(26, 0));  // nodeColor[node]['c'] => Of all the paths ending at 'node', what is the max freq of color 'c'
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
            nodeColor[i][colors[i] - 'a'] = 1;  // starting from this node only, so give it's color to it, populate it
        }

        int ans = 0;
        int cntNodes = 0;  // for cycle detection
        while(!q.empty()){
            int u = q.front();
            q.pop();

            cntNodes++;
            ans = max(ans, nodeColor[u][colors[u] - 'a']);

            // visit all adjacent nodes of 'u'
            for(int& v: adj[u]){
                // we are going from u->v, so update all colors freq at v => t[v][a], t[v][b], t[v][c]...
                for(int col = 0; col < 26; col++){
                    nodeColor[v][col] = max(nodeColor[v][col], nodeColor[u][col] + (colors[v]-'a' == col));
                }

                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        if(cntNodes < n) return -1;

        return ans;
    }
};
// What I could extract from the problem statement:
// We need to start from the nodes having indegree = 0, bcz they will be starting points of the paths, all the other ones will be middle ones, and won't result in longest path
// For each node, we would need to know what is the max frequency of each color till that node: Of all the paths ending at that 'node', what is the max freq of each color
// We also need to detect cycle if present
// From these observations, we can conclude that we can use Topological sort (Kahn's algorithm), to detect cycle, maintaing max freq till each node, start from indegree == 0, topological order