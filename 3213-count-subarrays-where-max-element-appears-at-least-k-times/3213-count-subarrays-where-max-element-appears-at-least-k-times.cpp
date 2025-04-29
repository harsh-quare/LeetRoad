class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        
        int i = 0, j = 0;
        int cnt = 0;
        while(j < n){
            cnt += (nums[j] == maxi);

            while(cnt >= k && i <= j){
                ans += n-j;
                cnt -= (nums[i] == maxi);
                i++;
            }

            j++;
        }
        
        return ans;
    }
};