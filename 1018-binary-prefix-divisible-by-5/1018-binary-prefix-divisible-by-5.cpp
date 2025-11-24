class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0];
        vector<bool> ans(n, false);
        ans[0] = (num == 0);
        
        for(int i = 1; i < n; i++){
            num = num << 1; // num *= 2
            num |= nums[i];

            num %= 5;

            ans[i] = (num % 5 == 0);
        }

        return ans;
    }
};