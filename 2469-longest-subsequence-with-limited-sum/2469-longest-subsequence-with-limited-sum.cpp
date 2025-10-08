class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // to get the maximum size of a subsequence(order doesn't matter) => I will try to take smaller elements of nums to maximize the size => get the upper_bound
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }

        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            int size = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            ans[i] = size;
        }

        return ans;
    }
};