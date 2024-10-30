class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        //calculate LIS for each position from left to right
        vector<int> lis(n, 1);
        for(int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        
        //calculate LDS for each position from right to left
        vector<int> lds(n, 1);
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(nums[j] < nums[i]){
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        
        //calculate the maximum mountain length
        int maxMountain = 0;
        for(int i = 1; i < n - 1; ++i){
            if(lis[i] > 1 && lds[i] > 1){  // valid peak condition
                maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
            }
        }
        
        return n - maxMountain;
    }
};
