class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < n; i++){
            if(maxi < i) return false; //index i can't be reached
            maxi = max(maxi, i + nums[i]);  //take the jump of nums[i]
        }   
        return true;
    }
};