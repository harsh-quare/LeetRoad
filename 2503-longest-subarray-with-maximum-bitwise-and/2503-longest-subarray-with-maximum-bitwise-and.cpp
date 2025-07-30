class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxAND = 0;
        for(int i = 0; i < n; i++){
            maxAND = max(maxAND, nums[i]);
        }

        int len = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxAND){
                len++;
                ans = max(ans, len);
            }
            else{
                len = 0;
            }
        }

        return ans;
    }
};