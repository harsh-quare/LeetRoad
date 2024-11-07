class Solution {
public:
    int solve(int id, vector<int>& nums, int curOr, int maxOr){
        if(id >= nums.size()){ 
            return (curOr == maxOr ? 1 : 0);
        }

        //Not include
        int notPick = solve(id+1, nums, curOr, maxOr);

        //include current element
        int pick = solve(id+1, nums, curOr | nums[id], maxOr);

        return pick + notPick;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto x: nums) maxi = maxi | x;
        return solve(0, nums, 0, maxi);
    }
};