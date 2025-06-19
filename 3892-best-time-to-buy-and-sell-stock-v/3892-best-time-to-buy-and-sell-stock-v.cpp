class Solution {
public:
    long long solve(int i, int txTyp, int cap, vector<int>& nums, int n, vector<vector<vector<long long>>>& dp){
        if(cap <= 0) return 0;
        if(i >= n){
            if(txTyp == 0) return 0;
            else return LLONG_MIN/2;  // invalidate path, unfinished transaction
        }

        if(dp[i][txTyp][cap] != -1) return dp[i][txTyp][cap];

        // long long ans = 0;  
        // Later in recursive branches, if all paths are invalid, e.g., you end recursion with an unfinished transaction, your function should return something very negative so the upper path avoids this branch.
// But since you're defaulting ans = 0, the logic says: “Even if all branches fail or are invalid, the best profit is still 0”
// That’s wrong — especially when you're in the middle of a transaction.
        long long ans = LLONG_MIN / 2;
        // This now tells the recursive function: “I assume nothing is profitable here unless a valid transaction path changes my mind.” This correctly propagates invalid branches upward, avoiding their inclusion in the final result.

        if(txTyp == 0){
            // op1: skip
            ans = max(ans, solve(i+1, 0, cap, nums, n, dp));
            // op2: buy normal
            ans = max(ans, -nums[i] + solve(i+1, 1, cap, nums, n, dp));
            // op3: sell short
            ans = max(ans, nums[i] + solve(i+1, 2, cap, nums, n, dp));
        }
        else if(txTyp == 1){
            // bought a normal stock in past
            // op1: skip
            ans = max(ans, solve(i+1, 1, cap, nums, n, dp));
            // op2: sell, one transcation completed
            ans = max(ans, nums[i] + solve(i+1, 0, cap - 1, nums, n, dp));
        }
        else if(txTyp == 2){
            // sold a short stock in past'
            // op1: skip
            ans = max(ans, solve(i+1, 2, cap, nums, n, dp));
            // op-2: buy and finish the transaction
            ans = max(ans, -nums[i] + solve(i+1, 0, cap - 1, nums, n, dp));
        }

        return dp[i][txTyp][cap] = ans;
    }
    long long maximumProfit(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(3, vector<long long>(k+1, -1)));
        return solve(0, 0, k, nums, n, dp);
    }
};

// if txTyp = 0 => can normal buy, or short sell
// if txTyp = 1 => previously bought a normal stock, can sell it now
// if txTyp = 2 => previously sold a short stock, can buy it now