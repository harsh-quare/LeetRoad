class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();  // Number of queries
        vector<bool> ans(m);  // Result vector to store boolean answers for each query

        // Prepare prefix array to store the count of consecutive elements with the same parity
        int n = nums.size();
        vector<int> prefix(n, 0);  // Prefix array to track same parity counts

        // Calculate prefix array
        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == nums[i - 1] % 2){  // Check if current and previous elements have the same parity
                prefix[i] = 1 + prefix[i - 1];  // Increment the count of same parity pairs
            } 
            else{
                prefix[i] = prefix[i - 1];  // No increment, carry forward the previous count
            }
        }

        // Process each query
        for(int i = 0; i < m; i++){
            int s = queries[i][0];  // Start index of the query range
            int e = queries[i][1];  // End index of the query range
            ans[i] = (prefix[e] - prefix[s] == 0);  // Check if no consecutive same-parity elements exist in the range
        }

        return ans;  // Return the result vector
    }
};