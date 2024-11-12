class Solution {
public:
    int getPrice(vector<vector<int>>& nums, int n, int q){
        int l = 0;
        int r = n-1;
        int resId = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid][0] <= q){
                resId = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return resId == -1 ? 0 : nums[resId][1];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        sort(items.begin(), items.end());

        for(int i = 1; i < n; i++){
            items[i][1] = max(items[i][1], items[i-1][1]);  // will ensure that, we are storing the maximum value of beauty from 0 till this index, for every index
        }

        vector<int> ans(m);
        for(int i = 0; i < queries.size(); i++){
            int q = queries[i];
            ans[i] = getPrice(items, n, q);
        }

        return ans;
    }
};