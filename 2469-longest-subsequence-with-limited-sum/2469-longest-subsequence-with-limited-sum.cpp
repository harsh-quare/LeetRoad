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
            int lo = 0;
            int hi = n-1;

            while(lo <= hi){
                int mid = lo + (hi-lo) / 2;

                if(nums[mid] > queries[i]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            ans[i] = lo;
        }

        return ans;
    }
};