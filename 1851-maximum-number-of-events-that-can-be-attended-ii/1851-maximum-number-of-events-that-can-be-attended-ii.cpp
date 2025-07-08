class Solution {
public:
    int findNext(vector<vector<int>>& events, int tar, int n){
        // find an event whose startTime is just greater than target(endTime of current event)
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(events[mid][0] > tar){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
    int solve(int i, int k, vector<vector<int>>& events, int n, vector<vector<int>>& dp){
        if(i >= n || k <= 0){
            return 0;
        }

        if(dp[i][k] != -1) return dp[i][k];

        int ans = 0;

        // skip current event
        ans = max(ans, solve(i + 1, k, events, n, dp));

        // attend current event
        int nextValidDay = findNext(events, events[i][1], n);
        ans = max(ans, events[i][2] + solve(nextValidDay, k-1, events, n, dp));

        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return solve(0, k, events, n, dp);
    }
};
// sort krne se hame har din ye pta krna easy rahega ki kitne events aaj chalu ho rhe h, and kisko attend krna best rahega
// states of dp will be, currDay, remainingCapacity(k)