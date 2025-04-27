class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;
        long long eqs = 0;

        unordered_map<long long, int> mp;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] % modulo == k) eqs++;

            int rem = eqs % modulo;
            int needed = (rem - k + modulo) % modulo;

            ans += mp[needed];
            mp[rem]++;
        }

        return ans;
    }
};