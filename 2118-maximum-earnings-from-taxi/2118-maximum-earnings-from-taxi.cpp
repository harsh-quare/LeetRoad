class Solution {
public:
    int findNext( vector<vector<int>>& rides, int tar, int n){
        // we need to find a start point in rides[i][0], which is just greater than equal to tar
        if(tar >= n) return rides.size();  // isse nextIndex = rides.size() hoga, jo first check me hi return 0 kr dega 
        int low = 0;
        int high = rides.size() - 1;
        int ans = rides.size();

        while(low <= high){
            int mid = low + (high - low)/2;

            if(rides[mid][0] >= tar){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
    long long solve(int i, vector<vector<int>>& rides, int n, vector<long long>& dp){
        if(i >= rides.size()) return 0;

        if(dp[i] != -1) return dp[i];

        long long ans = 0;

        // skip current passenger
        ans = max(ans, solve(i+1, rides, n, dp));

        // take current passenger
        long long curProf = rides[i][1] - rides[i][0] + rides[i][2];
        int nextValidStart = findNext(rides, rides[i][1], n);  // next start point, where passenger is available
        ans = max(ans, curProf + solve(nextValidStart, rides, n, dp));

        return dp[i] = ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size() + 1, -1);
        return solve(0, rides, n, dp);
    }
};