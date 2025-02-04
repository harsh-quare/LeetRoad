class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int curSum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){  //strictly ascending hona chahiye
                curSum = 0;
            }
            curSum += nums[i];
            ans = max(ans, curSum);
        }

        return ans;
    }
};