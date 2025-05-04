class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt++;
                ans += cnt;
            }
            else cnt = 0;
        }

        return ans;
    }
};