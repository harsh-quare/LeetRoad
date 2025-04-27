class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        // brute force
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(j-i+1 == 3 && nums[i+1] == (nums[i] + nums[j])*2) ans++;
            }
        }
        return ans;
    }
};