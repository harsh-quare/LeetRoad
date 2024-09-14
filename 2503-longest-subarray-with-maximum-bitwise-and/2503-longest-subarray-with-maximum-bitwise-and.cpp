class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int maxLen = 0;
        int curLen = 0;
        for(int i = 0; i<nums.size(); i++){
            if(maxi == nums[i]){
                curLen++;
            }
            else{
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
        }

        maxLen = max(maxLen, curLen); //for last subarray

        return maxLen;
    }
};