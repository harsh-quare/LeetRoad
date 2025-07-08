class Solution {
public:
    int findNext(vector<pair<int, pair<int, int>>>& jobs, int tar){
        int low = 0;
        int high = jobs.size() - 1;
        int ans = jobs.size();  // we need to find the first guy whose startTime is greater than equal to target
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(jobs[mid].first >= tar){
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }

        return ans;
    }
    int solve(int i, vector<pair<int, pair<int, int>>>& jobs, vector<int>& dp){
        if(i >= jobs.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = 0;

        ans = max(ans, solve(i+1, jobs, dp));

        int nextValidDay = findNext(jobs, jobs[i].second.first);  // jobs, curJobEndDay  // or either u can use lowerbound
        ans = max(ans, jobs[i].second.second + solve(nextValidDay, jobs, dp));

        return dp[i] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], {endTime[i], profit[i]}});
        }

        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, -1);

        return solve(0, jobs, dp);
    }
};