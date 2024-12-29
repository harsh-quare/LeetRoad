class Solution {
public:
    const int mod = 1e9 + 7;
    // long long solve(int tar_id, int dict_id, int n, int m, string& tar, vector<vector<long long>>& freq, vector<vector<long long>>& dp){
    //     if(tar_id >= m) return 1;
    //     if(dict_id >= n) return 0;

    //     if(dp[tar_id][dict_id] != -1) return dp[tar_id][dict_id];

    //     int not_take = solve(tar_id, dict_id + 1, n, m, tar, freq, dp) % mod;

    //     char ch = tar[tar_id];
    //     int take = freq[dict_id][ch - 'a'] * solve(tar_id + 1, dict_id + 1, n, m, tar, freq, dp) % mod;

    //     return dp[tar_id][dict_id] = (take + not_take) % mod;
    // }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();

        vector<vector<long long>> freq(n, vector<long long>(26, 0));
        for(int i = 0; i < n; i++){
            for(auto& s: words){
                char ch = s[i];
                freq[i][ch-'a']++;
            }
        }

        vector<long long> cur(m, 0), next(m + 1, 0);

        for (int dict_id = n; dict_id >= 0; dict_id--) {
            for (int tar_id = m; tar_id >= 0; tar_id--) {
                if(tar_id == m) {
                    next[m] = 1;
                    continue;
                }
                if(dict_id == n) continue;

                int not_take = next[tar_id];

                int take = 0;
                if(freq[dict_id][target[tar_id] - 'a'] != 0){
                    int cur_freq = freq[dict_id][target[tar_id]-'a'];
                    take = (cur_freq * (long long)next[tar_id + 1]) % mod;
                }

                cur[tar_id] = (take + not_take) % mod;
            }

            next = cur;
        }

        return next[0];
    }
};