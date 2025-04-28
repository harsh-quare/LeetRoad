class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // There are two cases from which we can get the maximum circular subarr sum
        // 1. When the entire subarry is inside the nums
        // 2. When there is overlapping, means some elements from end of the nums and some from beginning of nums in that subarr, means 0,...,i-1, i,...,j, j+1,...,n-1
        
        // For case 1, we can get the sum by using Kadane's algo directly
        // But for the case-2, we see that elements are in both ends of the array to form the maximum sum subarr
        // If we try to see, we notice that if we are getting maximum subarr circular from both ends of the array, then the subarr in between (i,...,j) will be having the minimum subarray sum

        // TotalSum = s1 + s2
        // if s1 is maximum, then s2 will be minimum for sure

        // We can simply calculate minimum subarray sum by using Kadane's similarly

        int maxSum1 = kadaneMax(nums);  // case-1 answer
        int total = accumulate(nums.begin(), nums.end(), 0);
        int minSubarrSum = kadaneMin(nums);
        int maxSum2 = total - minSubarrSum;  // case-2 answer

        if(maxSum2 > 0){
            return max(maxSum1, maxSum2);
        }

        return maxSum1;
    }

    int kadaneMax(vector<int>& nums){
        int n = nums.size();
        int maxi = nums[0];
        int cur = nums[0];

        for(int i = 1; i < n; i++){
            cur = max(cur + nums[i], nums[i]);
            maxi = max(maxi, cur);
        }

        return maxi;
    }

    int kadaneMin(vector<int>& nums){
        int n = nums.size();
        int mini = nums[0];
        int cur = nums[0];

        for(int i = 1; i < n; i++){
            cur = min(cur + nums[i], nums[i]);
            mini = min(mini, cur);
        }

        return mini;
    }
};