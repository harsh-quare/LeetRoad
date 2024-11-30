class Solution {
public:
    // Why this is problem is Euler's path finding or Euler's cycle finding problem
    // 1. We need to somehow choose the starting/source node
    // 2. We need to visit all the edges
    // 3. We need to visit all the edges exactly once

    //All 3 conditions satisfy the requirements of this proble, that's why this is a euler's path finding problem
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Heirholzer's algorithm
        
        // step-1: Build adjacency list
        // step-2: build indegree and outdegree
        // step-3: find the startNode of EulerPath

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;
        for(auto& p: pairs){
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        // find start node
        int startnode = pairs[0][0];
        for(auto& it: adj){
            int node = it.first;
            if(outdegree[node]-indegree[node] == 1){
                startnode = node;
                break;
            }
        }

        //start dfs and put the guys in stack that are coming in path
        //simple dfs
        stack<int> st;  //to perform dfs
        vector<int> eulerPath; //to store the path
        
        st.push(startnode);
        while(!st.empty()){
            int cur = st.top();
            if(!adj[cur].empty()){
                int nbr = adj[cur].back();
                adj[cur].pop_back();  // kind of visited mark kr diya
                st.push(nbr);
            }
            else{
                //agar cur ka koi nbr nhi h, to ye last node h, isko ab path me add kr skte h
                eulerPath.push_back(cur);
                st.pop();
            }
        }

        //ab hamara sequence, reverse order me eulerPath me store ho chuka h, to ya to reverse order me traverse krte hue le lo numbers ya fir vectore reverse krke fir lelo
        vector<vector<int>> ans;
        for(int i = eulerPath.size()-1; i >= 1; i--){
            int st = eulerPath[i];
            int e = eulerPath[i-1];
            ans.push_back({st, e});
        }

        return ans;
    }
};