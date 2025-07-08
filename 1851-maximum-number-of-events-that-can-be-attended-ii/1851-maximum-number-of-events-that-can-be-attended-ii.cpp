class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& events, int n, vector<int>& stDays, vector<vector<int>>& dp){
        if(i >= n || k <= 0){
            return 0;
        }

        if(dp[i][k] != -1) return dp[i][k];

        int ans = 0;

        // skip current event
        ans = max(ans, solve(i + 1, k, events, n, stDays, dp));

        // attend current event
        int nextValidDay = upper_bound(stDays.begin() + i, stDays.end(), events[i][1]) - stDays.begin();
        ans = max(ans, events[i][2] + solve(nextValidDay, k-1, events, n, stDays, dp));

        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> stDays;
        for(int i = 0; i < n; i++){
            stDays.push_back(events[i][0]);
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return solve(0, k, events, n, stDays, dp);
    }
};
// sort krne se hame har din ye pta krna easy rahega ki kitne events aaj chalu ho rhe h, and kisko attend krna best rahega
// states of dp will be, currDay, remainingCapacity(k)