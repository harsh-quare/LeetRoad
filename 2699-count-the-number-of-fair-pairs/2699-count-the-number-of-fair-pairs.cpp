class Solution {
public:
    long long findLowerBound(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        long long ans = 0;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target){
                ans += 1LL*(right - left);
                left++;
            }
            else
                right--;
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long low = findLowerBound(nums, lower);
        long long high = findLowerBound(nums, upper + 1);
        return high - low;
    }
};