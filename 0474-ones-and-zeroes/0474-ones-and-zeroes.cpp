class Solution {
public:
    int count[600][2]; // Keeping count of 0's and 1's for each string
    int dp[600][101][101];
    int find(int i, int m, int n, vector<string>& strs) {
        if (i >= strs.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int res = find(i + 1, m, n, strs); // Case1 skip the current string
        // Case2
        if (count[i][0] <= m && count[i][1] <= n) {
            res = max(res,
                      1 + find(i + 1, m - count[i][0], n - count[i][1], strs));
        }
        return dp[i][m][n] = res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(count, 0, sizeof(count));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < strs.size(); i++)
            for (auto& c : strs[i])
                count[i][c - '0']++;
        return find(0, m, n, strs);
    }
};