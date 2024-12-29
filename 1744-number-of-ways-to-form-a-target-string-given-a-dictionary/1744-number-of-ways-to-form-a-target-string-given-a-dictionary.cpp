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

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        
        //Base case-1: if(tar_id == m) return 1;
        for(int dict_id = 0; dict_id <= n; dict_id++){
            dp[m][dict_id] = 1;
        }

        //Bottom-up: loops opposite
        for(int dict_id = n-1; dict_id >= 0; dict_id--){
            for(int tar_id = m-1; tar_id >= 0; tar_id--){
                int not_take = dp[tar_id][dict_id + 1] % mod;

                char ch = target[tar_id];
                int take = freq[dict_id][ch - 'a'] * dp[tar_id + 1][dict_id + 1] % mod;

                dp[tar_id][dict_id] = (take + not_take) % mod;
            }
        }

        // for(int j = 0; j <= m; j++){
        //     for(int i = 0; i <= n; i++){
        //         cout << dp[j][i] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[0][0];
    }
};