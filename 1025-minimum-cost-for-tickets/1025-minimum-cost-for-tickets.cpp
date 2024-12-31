class Solution {
public:
    int solve(vector<int>& days, vector<int>& cs, int id, vector<int>& dp){
        if(id >= days.size()) return 0;

        if(dp[id] != -1) return dp[id];

        int next_idx = lower_bound(days.begin(), days.end(), days[id] + 1) - days.begin();
        int one_day = cs[0] + solve(days, cs, next_idx, dp);

        next_idx = lower_bound(days.begin(), days.end(), days[id] + 7) - days.begin();
        int seven_day = cs[1] + solve(days, cs, next_idx, dp);

        next_idx = lower_bound(days.begin(), days.end(), days[id] + 30) - days.begin();
        int thirty_day = cs[2] + solve(days, cs, next_idx, dp);

        return dp[id] = min(one_day, min(seven_day, thirty_day));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return solve(days, costs, 0, dp);
    }
};