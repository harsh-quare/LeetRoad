class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum % p == 0) return 0;

        // (TotalSum - subArrSum) % p == 0
        // TotalSum % p == subArrSum % p
        // let TotalSum % p == targetRemainder
        int target = sum % p;
        //Now I need a subarray whose sum%p == target

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefSum = 0;
        int minLen = nums.size();
        for(int i = 0; i < nums.size(); i++){
            prefSum += nums[i];
            int curRem = prefSum % p;
            int needed = (curRem - target + p) % p;

            if(mp.find(needed) != mp.end()){
                minLen = min(minLen, i - mp[needed]);
            }

            mp[curRem] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};