class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int curCnt = 1;
        int prevCnt = 0;
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                curCnt++;
            }
            else{
                prevCnt = curCnt;
                curCnt = 1;
            }

            ans = max(ans, max(curCnt/2, min(curCnt, prevCnt)));
        }

        return ans;
    }
};