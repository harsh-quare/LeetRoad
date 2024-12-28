class Solution {
public:
    // helper function is to get the sum of subarr if the index i is taken
    int helperSum(int cnt, int k, int i, vector<int>& subarrSum, vector<vector<int>>& dp){
        if(cnt == 0) return 0;
        if(i >= subarrSum.size()) return INT_MIN;

        if(dp[i][cnt] != -1) return dp[i][cnt];

        int take = subarrSum[i] + helperSum(cnt-1, k, i+k, subarrSum, dp);
        int notTake = helperSum(cnt, k, i+1, subarrSum, dp);

        return dp[i][cnt] = max(take, notTake);
    }

    // solve function is to verify if we need to take the current index in our answer or not
    void solve(int cnt, int k, int i, vector<int>& res, vector<int>& subarrSum, vector<vector<int>>& dp){
        if(cnt == 0) return ;
        if(i >= subarrSum.size()) return ;

        int take_i = subarrSum[i] + helperSum(cnt-1, k, i + k, subarrSum, dp);
        int not_take_i = helperSum(cnt, k, i+1, subarrSum, dp);

        if(take_i >= not_take_i){
            res.push_back(i);
            solve(cnt-1, k, i+k, res, subarrSum, dp);
        }
        else{
            solve(cnt, k, i+1, res, subarrSum, dp);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int> subarrSum;
        // int rsum= 0;
        // for(int i = 0; i < k; i++){
        //     rsum += nums[i];
        // }
        // subarrSum.push_back(rsum);
        // int i = 1, j = k;
        // while(j < n){
        //     rsum -= nums[i-1];
        //     rsum += nums[j];
        //     subarrSum.push_back(rsum);
        //     i++;
        //     j++;
        // }

        int i = 0, j = 0;
        vector<int> subarrSum;
        int rsum = 0;
        while(j < n){
            rsum += nums[j];

            if(j-i+1 == k){
                subarrSum.push_back(rsum);
                rsum -= nums[i];
                i++;
            }

            j++;
        }
        vector<int> res;
        int cnt = 3;
        vector<vector<int>> dp(n, vector<int>(4, -1));
        solve(cnt, k, 0, res, subarrSum, dp);
        return res;
    }
};