class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        if(n < 3) return 0;
        int curLen = 0;

        for(int i = 2; i < n; i++){
            int diff1 = nums[i] - nums[i-1];
            int diff2 = nums[i-1] - nums[i-2];

            if(diff1 == diff2) {
                curLen++;
                cnt += curLen;
            }
            else curLen = 0;
        }

        return cnt;
    }
};