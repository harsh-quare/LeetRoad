class Solution {
public:
    long long solve(int i, vector<long long>& nums, unordered_map<int, int>& mp, vector<long long>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        long long notTake = solve(i+1, nums, mp, dp);

        int nextValidId = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin();

        long long take = nums[i]*mp[nums[i]] + solve(nextValidId, nums, mp, dp);

        return dp[i] = max(take, notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for(int &x: power) mp[x]++;

        vector<long long> nums(mp.size());
        for(auto &[val, freq]: mp){
            nums.push_back(val);
        }

        sort(nums.begin(), nums.end());

        vector<long long> dp(nums.size(), -1);

        return solve(0, nums, mp, dp);
    }
};