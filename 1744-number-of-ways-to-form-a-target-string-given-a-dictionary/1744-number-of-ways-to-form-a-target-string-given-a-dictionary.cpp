class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[1001][1001];

    int solve(int tar_id, int dict_id, int n, int m, string& tar, vector<vector<long long>>& freq){
        // take or not_take
        if(tar_id == m) return 1;
        if(dict_id == n) return 0;

        if(dp[tar_id][dict_id] != -1) return dp[tar_id][dict_id];

        int not_take = solve(tar_id, dict_id + 1, n, m, tar, freq) % mod;
        
        char ch = tar[tar_id];
        int take = freq[dict_id][ch-'a'] * solve(tar_id + 1, dict_id + 1, n, m, tar, freq) % mod;

        return dp[tar_id][dict_id] = (take + not_take) % mod;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();

        vector<vector<long long>> freq(n, vector<long long>(26, 0));
        for(auto& s: words){
            for(int i = 0; i < n; i++){
                char ch = s[i];
                freq[i][ch-'a']++;
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n, m, target, freq) % mod;
    }
};