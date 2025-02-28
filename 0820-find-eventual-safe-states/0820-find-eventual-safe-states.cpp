class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            // i -> graph[i]
            // we are reversing=> i <- graph[i]
            for(auto x: graph[i]){
                adjRev[x].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};