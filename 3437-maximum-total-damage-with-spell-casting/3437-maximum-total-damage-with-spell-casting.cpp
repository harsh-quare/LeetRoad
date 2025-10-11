class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for(int x : power) freq[x]++;

        vector<int> vals;
        for (auto& [v, _] : freq) vals.push_back(v);
        sort(vals.begin(), vals.end());

        int m = vals.size();
        vector<long long> dp(m + 1, 0);

        for (int i = m - 1; i >= 0; --i) {
            long long gain = 1LL * vals[i] * freq[vals[i]];
            int j = upper_bound(vals.begin(), vals.end(), vals[i] + 2) - vals.begin();
            dp[i] = max(dp[i + 1], gain + dp[j]);
        }
        return dp[0];
    }
};