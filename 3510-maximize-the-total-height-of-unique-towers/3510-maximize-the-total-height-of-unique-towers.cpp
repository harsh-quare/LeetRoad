class Solution {
public:
    long long maximumTotalSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int last = nums.back() + 1;

        for(int i = nums.size()-1; i>=0; i--){
            last = min(last-1, nums[i]);

            if(last <= 0) return -1;

            ans += last;
        }

        return ans;
    }
};