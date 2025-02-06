class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int curSum = 0;
        unordered_map<int, int> mp;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            curSum += nums[j];
            if(curSum == k) cnt++;
            cnt += mp[curSum - k];
            mp[curSum]++;
        }

        return cnt;
    }
};