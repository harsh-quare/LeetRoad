class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Better
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int a = nums[i], b = nums[j];
                int idx = lower_bound(nums.begin()+j+1, nums.end(), a+b) - nums.begin();    // check from j+1->n-1

                ans += (idx - j - 1);  // from j to the 1st invalid index for this pair => everything is valid
            }
        }

        return ans;
    }
};