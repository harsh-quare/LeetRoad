class Solution {
public:
    // Euler's path finding problem
    // start point is given
    // all edges must be traversed
    // all edges must be visited exactly once
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //Heirholzer's algo
        // build adjacency
        // build indegree and outdegre : to determine start node: given
        // find path

        unordered_map<string, vector<string>> adj;
        for(auto& t: tickets){
            string u = t[0];
            string v = t[1];

            adj[u].push_back(v);
        }

        for(auto& t: adj){
            vector<string> x = t.second;
            sort(x.begin(), x.end());
            reverse(x.begin(), x.end());
            t.second = x;
        }

        //given start node, start dfs from there and find the path
        stack<string> st;
        vector<string> eulerPath;
        st.push("JFK");

        while(!st.empty()){
            string cur = st.top();

            if(!adj[cur].empty()){
                string nbr = adj[cur].back();
                st.push(nbr);
                adj[cur].pop_back();  //mark visited
            }
            else{
                // if no neighors are present
                // means this is the last node
                //include in the path
                eulerPath.push_back(cur);
                st.pop();
            }
        }

        reverse(eulerPath.begin(), eulerPath.end());
        return eulerPath;
    }
};