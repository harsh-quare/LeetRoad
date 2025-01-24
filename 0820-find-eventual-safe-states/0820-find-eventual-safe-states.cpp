class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // dfs and stack
        // bfs and indegree array
        //Using Topo sort / BFS
        //what do we need in topo sort
        //the node whose indegree is 0, goes into queue
        //but here, we need to explore path which has outdegree as 0 i.e. terminal node
        //for that, we will reverse all edges of graph
        
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n,0);

        for(int i = 0; i<n; i++){
            for(auto it: graph[i]){
                // i -> it
                // it -> i
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};