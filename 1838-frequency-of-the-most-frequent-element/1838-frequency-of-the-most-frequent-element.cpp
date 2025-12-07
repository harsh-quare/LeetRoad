class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Method-2: instead of calculating and cummulating ops and cnt at each step, keep the sum of the subarray and calculate req ops by target*length - curSum
        // Method-3: Instead of iterating back to already visited array, to calculate the ops, try to maintain curSum of the array, and try to shrink window for each index if the required operations exceed k and as soon you get the valid window, update ans by the current length and previous ans

        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        long curSum = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            
            long target = nums[right];
            curSum += nums[right];

            while((right - left + 1) * target - curSum > k){
                curSum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};