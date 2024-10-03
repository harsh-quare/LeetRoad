class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        int target = sum % p;
        if(target == 0) return 0;

        unordered_map<int, int> mp;
        int prefSum = 0, minLen = n;
        mp[0] = -1;

        for(int i = 0; i < n; i++){
            prefSum = (prefSum + nums[i]) % p;

            int needed = (prefSum - target + p) % p;

            if(mp.find(needed) != mp.end()){
                minLen = min(minLen, i - mp[needed]);
            }

            mp[prefSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};