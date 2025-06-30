class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     cout << nums[i] << ", ";
        // }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int mx = nums[i] + 1;
            int mxid = upper_bound(nums.begin() + i, nums.end(), mx) - nums.begin();
            if(nums[mxid-1] != mx) continue; //invalid, skip kro

            int curAns = mxid - i;
            ans = max(ans, curAns);
        }

        return ans;
    }
};