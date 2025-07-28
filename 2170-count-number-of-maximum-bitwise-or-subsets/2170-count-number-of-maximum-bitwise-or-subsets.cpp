class Solution {
public:
    int solve(int i, int curOr, int maxOr, int n, vector<int>& nums){
        if(i >= n){
            return (curOr == maxOr);
        }

        int skip = solve(i+1, curOr, maxOr, n, nums);

        int take = solve(i+1, curOr | nums[i], maxOr, n, nums);

        return (take + skip);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = nums[0];
        for(int& x: nums){
            maxOr |= x;
        }

        return solve(0, 0, maxOr, n, nums);
    }
};