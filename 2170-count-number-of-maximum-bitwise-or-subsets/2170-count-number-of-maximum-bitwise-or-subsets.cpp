class Solution {
public:
    void solve(int id, vector<int>& nums, vector<int>& help, int& ans, int maxi){
        if(id >= nums.size()){
            int orSum = 0;
            for(auto& x: help) orSum = orSum | x;
            
            if(orSum == maxi){
                ans++;
            }   

            return ;
        }

        //include current element
        help.push_back(nums[id]);
        solve(id+1, nums, help, ans, maxi);
        help.pop_back(); //backtrack: vapas nikal do jisko daala tha, dusre path pe jaane se pahle

        //Not include
        solve(id+1, nums, help, ans, maxi);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> help;
        int ans = 0;
        int maxi = 0;
        for(auto x: nums) maxi = maxi | x;
        solve(0, nums, help, ans, maxi);
        return ans;
    }
};