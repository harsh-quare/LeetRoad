class Solution {
public:
    vector<int> solve_lis(vector<int>& nums){
        int n = nums.size();
        vector<int> lis(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }

        return lis;
    }

    vector<int> solve_lds(vector<int>& nums){
        int n = nums.size();
        vector<int> lds(n, 1);
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(nums[j] < nums[i]){
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }

        return lds;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc = solve_lis(nums);  //get the length of longest increasing subsequence, ending at each point
        vector<int> dec = solve_lds(nums);  //get the length of longest decreasing subsequence, starting from each point

        int mountainArrLen = 0;
        for(int i = 1; i < n - 1; i++){  // Peaks must be between the first and last elements
            if(inc[i] > 1 && dec[i] > 1){  // Valid mountain peak
                mountainArrLen = max(mountainArrLen, inc[i] + dec[i] - 1);
            }
        }

        return n - mountainArrLen;
    }
};