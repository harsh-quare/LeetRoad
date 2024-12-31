class Solution {
public:
    int tabu(vector<int>& days, vector<int>& cs){
        vector<int> dp(days.size() + 1, 0);

        for(int i = days.size()-1; i >= 0; i--){
            int op1 = cs[0] + dp[i+1];

            int op2 = 0;
            int day_after_7 = days[i] + 6;
            int new_id = upper_bound(days.begin(), days.end(), day_after_7) - days.begin();
            op2 = cs[1] + dp[new_id];

            int op3 = 0;
            int day_after_30 = days[i] + 29;
            int new_id2 = upper_bound(days.begin(), days.end(), day_after_30) - days.begin();
            op3 = cs[2] + dp[new_id2];

            dp[i] = min(op1, min(op2, op3));
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = tabu(days, costs);
        return ans;
    }
};