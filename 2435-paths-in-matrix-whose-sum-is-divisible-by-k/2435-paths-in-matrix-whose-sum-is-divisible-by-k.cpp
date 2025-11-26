class Solution {
public:
    const int mod = 1e9 + 7;
    // int solve(int i, int j, int cur, vector<vector<int>>& grid, int k, int n, int m, vector<vector<vector<int>>>& dp){
    //     if(i == n-1 && j == m-1){
    //         cur = (cur + grid[i][j]) % k;
    //         if(cur % k == 0) return 1;
    //         else return 0;
    //     }

    //     if(dp[i][j][cur] != -1) return dp[i][j][cur];
        
    //     int down = 0;
    //     if(i+1 < n) down = solve(i+1, j, (cur+grid[i][j])%k, grid, k, n, m, dp);
    //     int right = 0;
    //     if(j+1 < m) right = solve(i, j+1, (cur+grid[i][j])%k, grid, k, n, m, dp);

    //     return dp[i][j][cur] = (down + right) % mod;
    // }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        int dest = grid[n-1][m-1] % k;
        int need = (k - dest) % k;
        dp[n-1][m-1][need] = 1;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1) continue;
                int val = grid[i][j];

                for(int rem = 0; rem < k; rem++){
                    int new_rem = (rem + val) % k;

                    long long down = (i+1 < n ? dp[i+1][j][new_rem] : 0);
                    long long right = (j+1 < m ? dp[i][j+1][new_rem] : 0);
                    
                    dp[i][j][rem] = (down + right) % mod;
                }
            }
        }

        return dp[0][0][0];
    }
};