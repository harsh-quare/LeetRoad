class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int mini = nums[0];

        for(int i = 1; i < nums.size(); i++){
            ans += (nums[i] - mini);
        }

        return ans;
    }
};