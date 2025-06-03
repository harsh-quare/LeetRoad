class Solution {
public:
    int solve(int j, int cur_dig, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        if(j >= m){
            // reached end, and got out of the last column, jitns cost hua hoga, woh calculate kr chuke honge, to yaha se 0 return kr do, yaha se koi cost nhi lagega
            return 0;
        }

        if(dp[j][cur_dig] != -1) return dp[j][cur_dig];

        int cost = 0;
        for(int row = 0; row < n; row++){
            if(grid[row][j] != cur_dig) cost++;  // change all the values to cur_dig, and calculate its cost
        }

        // now, after putting cur_dig at current column, call for the next column to get the ans
        int minAns = INT_MAX;
        for(int try_dig = 0; try_dig <= 9; try_dig++){
            if(cur_dig != try_dig){
                minAns = min(minAns, cost + solve(j+1, try_dig, grid, n, m, dp));
            }
        }

        return dp[j][cur_dig] = minAns;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        // for each column, I have 10 options (technically 9, bcz can't take the one which was used by nbr)
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(10, -1));  // dp[column][digit]

        int ans = INT_MAX;
        for(int try_dig = 0; try_dig <= 9; try_dig++){
            // try each digit on column 0, and recursively call to get the minimum answer
            ans = min(ans, solve(0, try_dig, grid, n, m, dp));
        }

        return ans;
    }
};