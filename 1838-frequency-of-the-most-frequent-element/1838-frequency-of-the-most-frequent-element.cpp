class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int ans = 0;
        long long curSum = 0;  // in each window, number of required operations to all elements in window equal to the current right pointer value, will be equal to (right - left + 1) * nums[right] - curSum

        for(int right = 0; right < n; right++){
            long long target = nums[right];
            curSum += target;

            while((right - left + 1) * target - curSum > k){
                curSum -= nums[left];
                left++;
            }

            ans = max(ans, (right - left + 1));
        }

        return ans;
    }
};