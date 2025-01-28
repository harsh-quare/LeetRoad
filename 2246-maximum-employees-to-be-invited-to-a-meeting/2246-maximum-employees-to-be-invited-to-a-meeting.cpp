class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        
        // Build the graph and calculate in-degrees
        for (int i = 0; i < n; ++i) {
            graph[i].push_back(favorite[i]);
            inDegree[favorite[i]]++;
        }
        
        // Topological sort to find the longest chain
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> depth(n, 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                depth[v] = max(depth[v], depth[u] + 1);
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Find the maximum cycle length
        int maxCycle = 0;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] != 0) {
                int cycleLength = 0;
                int j = i;
                while (inDegree[j] != 0) {
                    inDegree[j] = 0;
                    j = favorite[j];
                    cycleLength++;
                }
                maxCycle = max(maxCycle, cycleLength);
            }
        }
        
        // Calculate the sum of the longest chains for mutual pairs
        int sumChains = 0;
        for (int i = 0; i < n; ++i) {
            if (favorite[favorite[i]] == i && i < favorite[i]) {
                sumChains += depth[i] + depth[favorite[i]];
            }
        }
        
        return max(maxCycle, sumChains);
    }
};