class Solution {
public:
    // long long solve(int i, vector<long long>& nums, unordered_map<int, int>& mp, vector<long long>& dp){
    //     if(i >= nums.size()) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     long long notTake = solve(i+1, nums, mp, dp);

    //     int nextValidId = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin();

    //     long long take = nums[i]*mp[nums[i]] + solve(nextValidId, nums, mp, dp);

    //     return dp[i] = max(take, notTake);
    // }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for(int &x: power) mp[x]++;

        vector<long long> nums(mp.size());
        for(auto &[val, freq]: mp){
            nums.push_back(val);
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> dp(nums.size(), 0);

        long long ans = LLONG_MIN;

        for(int i = n-1; i >= 0; i--){
            long long notTake = (i+1 < n) ? dp[i+1] : 0;

            int nextValidId = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin();

            long long take = nums[i] * mp[nums[i]] + ((nextValidId < n) ? dp[nextValidId] : 0);

            dp[i] = max(take, notTake);

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};