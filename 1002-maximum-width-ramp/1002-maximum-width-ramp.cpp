class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++){
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());
        int minId = vp[0].second;  //minimum index seen so far

        for(int i = 1; i < n; i++){
            ans = max(ans, vp[i].second - minId);
            minId = min(minId, vp[i].second);
        }

        return ans;
    }
};