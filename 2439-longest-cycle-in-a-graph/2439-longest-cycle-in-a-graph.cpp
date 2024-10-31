class Solution {
public:
    int longestCycle(std::vector<int>& edges) {
        int longest_cycle_length = -1;
        int n = edges.size();
        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++){
            if(vis[i] == -1){  
                int cycle_length = dfs(i, edges, vis, 0);
                if(cycle_length > longest_cycle_length){
                    longest_cycle_length = cycle_length;
                }
            }
        }

        return longest_cycle_length;
    }

    int dfs(int node, vector<int>& edges, vector<int>& vis, int depth){
        if(node == -1){ 
            return -1;  
        }
        if(vis[node] >= 0){
            return depth - vis[node];  
        }
        if(vis[node] == -2){
            return -1;
        }

        vis[node] = depth;
        int nextNode = edges[node];
        int cycle_length = dfs(nextNode, edges, vis, depth + 1);

        vis[node] = -2;
        
        return cycle_length >= 1 ? cycle_length : -1;
    }
};