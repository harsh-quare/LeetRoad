class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        int n = nums.size();

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = total;
        sort(nums.begin(), nums.end());

        long long pref = 0;

        for(int i = 0; i < n; i++){
            long long sumFront = total - (pref + nums[i]);  // sum of elements after current element
            long long removals = sumFront - (long long)nums[i]*(n-1-i);

            long long curTotal = pref + removals;
            ans = min(ans, curTotal);
            pref += nums[i];
        }

        return ans;
    }
};