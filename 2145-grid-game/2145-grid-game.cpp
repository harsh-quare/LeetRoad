class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottomSum = 0;
        int n = grid[0].size();

        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            topSum -= grid[0][i];
            long long curMax = max(bottomSum, topSum);
            ans = min(ans, curMax);
            bottomSum += grid[1][i];

            cout << ans << endl;
        }

        return ans;
    }
};