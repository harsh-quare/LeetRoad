class Solution {
public:
    pair<int, int> calcFarthestAndDist(int node, unordered_map<int, vector<int>>& adj){
        queue<int> q;
        q.push(node);
        unordered_map<int, bool> vis;
        vis[node] = true;
        
        int farthest = node;
        int maxDist = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int nd = q.front();
                q.pop();

                farthest = nd;

                for(auto it: adj[nd]){
                    if(!vis[it]){
                        vis[nd] = 1;
                        q.push(it);
                    }
                }
            }
            if(!q.empty()) maxDist++;
        }

        return {farthest, maxDist};
    }
    
    int calcDiameter(unordered_map<int, vector<int>> adj){
        // step-1: Get the farthest node from any randomly taken node, that farthest node will be one end of the diameter
        auto [end1, dist1] = calcFarthestAndDist(0, adj);
        
        // step-2: find the farthest node from this end point, that will be the other end of diameter, also calc diameter
        auto [end2, diameter] = calcFarthestAndDist(end1, adj);
        
        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;
        for(auto& it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges2);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges1);

        int diam1 = calcDiameter(adj1);
        int diam2 = calcDiameter(adj2);

        int combined_diam = ((diam1 + 1) / 2) + ((diam2 + 1) / 2) + 1;

        return max(diam1, max(diam2, combined_diam));
    }
};

// The main idea behind this problem is to :
// 1. Learn how to calculate the diameter of a tree/graph
//    -step1: From any random node, the farthest node will be the one end of the diameter of the tree
//    -step2: From any one end of diameter, the farthest node from that node will be the other end of the tree
//    -step3: Use BFS or DFS to calculate the tree diameter, and also the last processed node will be the end pt of diam

// The minimum diameter we'll get when we join the nodes which are in middle of both tree diameters
// So taking the ceiling of the diameter distances and also one extra for joining both trees

// 2. There may be 3 scenarios of the longest diameter after joining two nodes from different trees
//    i. The longest path might be from combined trees.
//    ii. The longest path might be from tree1 only.
//    iii. The longest path might be from tree2 only.