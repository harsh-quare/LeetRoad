class Solution {
public:
    // This function tries to solve, "subset sum equals k" problem using DP
    bool canZero(int mid, vector<int>& nums, vector<vector<int>>& q, int n) {
        // For each index, track possible decrements
        for(int i = 0; i < n; i++){
            int val = nums[i];
            vector<bool> dp(val + 1, false); //can we achieve this decrement???
            dp[0] = true; // Empty subset, 0 is achievable
            
            for(int j = 0; j < mid; j++){
                int l = q[j][0], r = q[j][1], x = q[j][2];
                if(i < l || i > r) continue; // i not in range
                
                //shift possible values by x
                for(int num = nums[i]; num >= x; num--){
                    if(dp[num - x] == true){
                        dp[num] = true;
                    }
                }
            }
            if(dp[val] == false) return false; //cannot make nums[i] exactly 0
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int low = 0;
        int high = queries.size();  // applying all queries

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canZero(mid, nums, queries, n)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};