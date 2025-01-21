class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> vp(2, vector<long long>(n+1, 0));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                vp[i][j+1] = vp[i][j] + grid[i][j];
            }
        }

        long long mini = LLONG_MAX;
        for(int j = 0; j < n; j++){
            if(j == 0) mini = min(mini, (long long)vp[0][n] - vp[0][j+1]);
            else if(j == n-1) mini = min(mini, (long long)vp[1][j] - vp[1][0]);
            else{
                long long maxi1 = vp[0][n] - vp[0][j+1];
                long long maxi2 = vp[1][j] - vp[1][0];

                mini = min(mini, max(maxi1, maxi2));
            }
        }

        return mini;
    }
};