class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        // array ko iss tarah se sort kro ki bade elements array ki beginning me aaye and unka relative index me order maintain rhe

        vector<pair<int, int>> vp(n);  // {index, value}
        for(int i = 0; i < n; i++){
            vp[i] = {i, nums[i]};
        }

        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int,int> b){
            return a.second > b.second;
        });

        // for(int i = 0; i < n; i++){
        //     cout << vp[i].first << ", " << vp[i].second << endl;
        // }

        // Now, we got the array sorted by values, now sort them based on their index as well(only first k indexes)
        sort(vp.begin(), vp.begin() + k);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(vp[i].second);
        }

        return ans;
    }
};