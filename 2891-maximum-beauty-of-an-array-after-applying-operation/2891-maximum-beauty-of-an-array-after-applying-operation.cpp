class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        //sliding window
        int left = 0, right = 0, ans = 0;
        int n = nums.size();

        while(right < n){
            //shrink window
            if(nums[right] - nums[left] > 2*k){
                left++;
            }

            else{
                int len = right - left + 1;
                ans = max(ans, len);
            }

            right++;
        }

        return ans;
    }
};