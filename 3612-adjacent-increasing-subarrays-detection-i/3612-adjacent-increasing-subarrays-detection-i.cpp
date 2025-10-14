class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = k; i <= n-k; i++){
            // (i-k)->(i-1)
            bool incLeft = true;
            for(int j = i-k+1; j < i; j++){  // skip first element, bcz that's already increasing
                if(nums[j] <= nums[j-1]){
                    incLeft = false;
                    break;
                }
            }

            // i->(i+k-1)
            bool incRight = true;
            for(int j = i+1; j < i+k; j++){  // skip first element, bcz that's already increasing
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