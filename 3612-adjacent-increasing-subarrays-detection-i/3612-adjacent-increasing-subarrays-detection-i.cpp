class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = k; i <= n-k; i++){
            // (i-k)->i
            bool incLeft = true;
            for(int j = i-k+1; j < i; j++){
                if(nums[j] <= nums[j-1]){
                    incLeft = false;
                    break;
                }
            }

            bool incRight = true;
            for(int j = i+1; j < i+k; j++){
                if(nums[j] <= nums[j-1]){
                    incRight = false;
                    break;
                }
            }

            if(incLeft && incRight) return true;
        }

        return false;
    }
};