class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // By solving the given conditions, I found out that, for the subarray elements to be reduced to zero by given operations, the elements' should have even number of 1 bits for every bit position
        // If we simplify this, we get that we have even number of set bits, means we can use xor property
        // 1^1 = 0, a^a = 0. i.e. If we somehow can get subarray xor equal to zero, that subarray is valid
        
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int xor_res = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            xor_res ^= nums[i];
            ans += mp[xor_res];
            mp[xor_res]++;
        }

        return ans;
    }
};