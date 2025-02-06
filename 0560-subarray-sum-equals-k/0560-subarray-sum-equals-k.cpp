class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int curSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            curSum += nums[j];
            int comp = curSum - k;
            if(mp.find(comp) != mp.end()){
                cnt += mp[comp];
            }
            mp[curSum]++;
        }

        return cnt;
    }
};