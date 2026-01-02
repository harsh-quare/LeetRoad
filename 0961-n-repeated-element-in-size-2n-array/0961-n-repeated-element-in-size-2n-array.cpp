class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == nums[n-1]) return nums[0];
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) return nums[i];
        }
        return nums[0];
    }
};