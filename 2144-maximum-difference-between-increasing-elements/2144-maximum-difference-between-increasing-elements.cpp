class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // buy and sell stock-1
        int n = nums.size();
        int maxi = INT_MIN;
        int minGuy = nums[0];
        
        for(int i = 1; i < n; i++){
            if(nums[i] > minGuy){
                maxi = max(maxi, nums[i] - minGuy);
            }
            else{
                minGuy = min(minGuy, nums[i]);
            }
        }

        return (maxi < 0) ? -1 : maxi;
    }
};