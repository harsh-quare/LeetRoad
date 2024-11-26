class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(auto& e: edges){
            int u = e[0];
            int v = e[1];

            indegree[v]++;
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                if(ans != -1){
                    return -1;  //already a guy with indegree 0 is found, single winner not possible
                }
                ans = i;
            }
        }

        return ans;
    }
};