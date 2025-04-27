class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        // brute force
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i <= n-3; i++){
            if(nums[i+1] == (nums[i] + nums[i+2])*2) ans++;
        }
        return ans;
    }
};