class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxiDiff = INT_MIN;
        for(int i = 0; i < n; i++){
            maxiDiff = max(maxiDiff, abs(nums[i] - nums[(i+1)%n]));
        }
        return maxiDiff;
    }
};