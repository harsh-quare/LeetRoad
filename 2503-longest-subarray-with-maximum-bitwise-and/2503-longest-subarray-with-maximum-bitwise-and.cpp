class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = nums[0];
        int curLen = 1;
        int maxLen = 1;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxLen = 1;
                curLen = 1;
            }
            else if(nums[i] == maxi){
                curLen++;
                maxLen = max(maxLen, curLen);
            }
            else{
                curLen = 0;
            }
        }

        return maxLen;
    }
};