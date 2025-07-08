class Solution {
public:
    int solve(int i, vector<int>& startTime, vector<vector<int>> &jobs, int n, vector<int>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int ans = 0;

        // skip current job
        ans = max(ans, solve(i + 1, startTime, jobs, n, dp));

        // attend current job, consume the profit
        // we use lower bound, bcz we can start next job, on the same day, our previous job finishes
        int nextValidDay = lower_bound(startTime.begin() + i, startTime.end(), jobs[i][1]) - startTime.begin();
        ans = max(ans, jobs[i][2] + solve(nextValidDay, startTime, jobs, n, dp));

        return dp[i] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());

        vector<int> dp(n+1, -1);
        return solve(0, startTime, jobs, n, dp);
    }
};

// first sort all of them based on startTime
// take a job or skip a job
// if you take a job, add it's profit to ans, and then find the next job which you can take by using binary search on startTime, to find a startTime which is just greater than our currently taken job's endTime