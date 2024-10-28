class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        int maxLen = 1;

        for(int i = n-2; i>=0; i--){
            long long tar= (long long)nums[i]*nums[i];

            //search for current value's square
            int low = i+1, high = n-1;
            int pos = -1;
            while(low <= high){
                int mid = low + (high-low)/2;

                if(nums[mid] == tar){
                    pos = mid;
                    break;
                }
                else if(nums[mid] > tar) high = mid-1;
                else if(nums[mid] < tar) low = mid+1;
            }

            int curLen;
            if(pos == -1) curLen = 1;
            else curLen = 1 + dp[pos];
            dp[i] = curLen;
            maxLen = max(maxLen, dp[i]);
        }
        if(maxLen == 1) return -1;
        return maxLen;
    }
};