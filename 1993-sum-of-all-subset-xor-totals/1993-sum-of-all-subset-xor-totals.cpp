class Solution {
public:
    void solve(vector<int>& nums, int i, int& total, int cur){
        if(i >= nums.size()){
            total += cur;
            return ;
        }

        // take
        solve(nums, i+1, total, cur^nums[i]);

        // notTake
        solve(nums, i+1, total, cur);

        return ;
    }
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        solve(nums, 0, total, 0);

        return total;
    }
};