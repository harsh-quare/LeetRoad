class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        int cons = 0;
        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i-1] + 1 == nums[i]){
                cons++;
            }
            else{
                cons = 0;
            }

            if(cons >= k-1){
                ans[i-k+1] = nums[i];
            }
        }

        return ans;
    }
};