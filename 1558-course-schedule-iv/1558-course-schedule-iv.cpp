class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<int> adj[numCourses];

        for(auto& it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<int>> isConnected(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            // from each node, start bfs and mark all the nodes as connected which comes on the path
            queue<int> q;
            vector<int> vis(n, 0);
            q.push(i);
            isConnected[i][i] = 1;

            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    int node = q.front();
                    q.pop();
                    vis[node] = 1;

                    isConnected[i][node] = 1;

                    for(auto it: adj[node]){
                        if(!vis[it]) q.push(it);
                    }
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << isConnected[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<bool> ans;
        for(auto &it: queries){
            int i = it[0];
            int j = it[1];
            ans.push_back(isConnected[i][j]);
        }
        return ans;
    }
};