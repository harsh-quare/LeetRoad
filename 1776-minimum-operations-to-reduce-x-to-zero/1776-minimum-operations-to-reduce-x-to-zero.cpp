class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int targ = total - x;
        if(targ == 0) return n;
        if(targ < 0) return -1;

        int curSum = 0;
        int ans = -1;
        int i = 0;
        for(int j = 0; j < n; j++){
            curSum += nums[j];

            while(curSum > targ && i <= j){
                curSum -= nums[i++];
            }

            if(curSum == targ){
                ans = max(ans, j-i+1);  // we want the maximum subarray whose sum is equal to (total - x). Because we are removing elements from both ends, and we want to minimize those removals, means we want the other sum to be from longest subarray, so that we remove minimally from both ends
            }
        }

        if(ans == -1) return -1;
        return n - ans;
    }
};