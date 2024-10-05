class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        if(nums[n/2] == k) return 0;

        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(nums[i] > k) ans+=(nums[i]-k);
            }
            else if(i == n/2) ans += abs(k-nums[i]);
            else{
                if(nums[i] < k) ans+=(k-nums[i]);
            }
        }

        return ans;
    }
};