class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + nums[i];
        }

        long long total = pref[n];
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if(pref[i+1] >= total - pref[i+1]){
                // cout << i << ": " << pref[i+1] << ", " << total - pref[i+1] << endl;
                cnt++;
            }
        }

        return cnt;
    }
};