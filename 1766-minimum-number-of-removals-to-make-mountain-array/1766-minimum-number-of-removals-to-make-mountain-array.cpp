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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis = solve_lis(nums);  //get the length of longest increasing subsequence, ending at each point
        reverse(nums.begin(), nums.end());
        vector<int> lds = solve_lis(nums);  //get the length of longest decreasing subsequence, starting from each point
        reverse(lds.begin(), lds.end());

        int mountainArrLen = 0;
        for(int i = 1; i < n - 1; i++){  // Peaks must be between the first and last elements
            if(lis[i] > 1 && lds[i] > 1){  // Valid mountain peak
                mountainArrLen = max(mountainArrLen, lis[i] + lds[i] - 1);
            }
        }

        return n - mountainArrLen;
    }
};