class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Sliding window technique
        // we can have at most one zero in between 
        // so we will try to calculate longest subarray with one occ of 0, and all other 1's

        int n = nums.size();
        int zeros = 0;
        int maxLen = 0;
        int i = 0;

        for(int j = 0; j < n; j++){
            if(nums[j] == 0) zeros++;  //current element

            // shrink the window if there are more than one 1's in this window
            while(zeros > 1){
                if(nums[i] == 0){
                    zeros--;
                }
                i++;
            }

            // update maxLen
            maxLen= max(maxLen, j-i+1);
        }
        return maxLen - 1; //bcz we included one 0 in our subarray
    }
};