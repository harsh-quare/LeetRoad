class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> sufixSumConsOnes(n, vector<int>(m, 0)); 

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = m-1; j >= 0; j--){
                if(mat[i][j] == 1){
                    cnt++;
                }
                else{
                    cnt = 0;
                }

                sufixSumConsOnes[i][j] = cnt;
            }
        }
        
        int ans = 0;
        // consider each point as top left point of the submetric and try to expand
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                // for each cell, get the min length of 1-d subarray of all ones from all the rows below it
                int minLen = INT_MAX;
                for(int r = i; r < n; r++){
                    minLen = min(minLen, sufixSumConsOnes[r][j]);
                    ans += minLen;   // counting all the submetrices whose top left point is grid[i][j]
                }
            }
        }

        return ans;
    }
};