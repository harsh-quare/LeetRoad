class Solution {
public:
    long long solve(int ida, int idb, vector<int>& a, vector<int>& b, vector<vector<long long>>& dp){
        if(ida >= 4) return 0;
        if(idb == b.size()-1){
            if(ida == 3) return (long long)a[ida]*b[idb];
            else return -1e14;
        }

        if(dp[ida][idb] != -1) return dp[ida][idb];

        // long long ans = LLONG_MIN;

        long long notTake = solve(ida, idb+1, a, b, dp);
        long long take = (long long)a[ida]*b[idb] + solve(ida+1, idb+1, a, b, dp);

        return dp[ida][idb] = max(take, notTake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(4, vector<long long>(b.size(), -1));
        return solve(0, 0, a, b, dp);
    }
};