class Solution {
public:
    int mod = 1e9 + 7;
    // vector<vector<int>> dp;
    // int solve(int i, int cnt, vector<int>& freq, int k){
    //     // base case
    //     if(i >= freq.size()){
    //         if(cnt < k) return 1;  // found invalid string
    //         else return 0;
    //     }

    //     if(dp[i][cnt] != -1) return dp[i][cnt];

    //     long long res = 0;
    //     for(int take = 1; take <= freq[i]; take++){  // har char ke liye, saari freq leke dekh lo
    //         if(cnt + take < k){
    //             res = (res + solve(i+1, cnt + take, freq, k)) % mod;
    //         }
    //         else{  // yaha se invalid nhi aayega, to pahle hi break kr jao
    //             break;
    //         }
    //     }

    //     return dp[i][cnt] = res;
    // }
    int possibleStringCount(string word, int k) {
        if(word.length() < k) return 0;

        vector<int> freq;  // continuous chars ki freq
        int cnt = 1;
        for(int i = 1; i < word.length(); i++){
            if(word[i] == word[i-1]){
                cnt++;
            }
            else{
                freq.push_back(cnt);
                cnt = 1;  // reset
            }
        }
        freq.push_back(cnt); // last grp

        long long totalPossible = 1; // total possible strings
        for(int &f: freq){
            totalPossible = (totalPossible * f) % mod;
        }

        if(freq.size() >= k) return totalPossible; //considering if only one-one chars are taken, and still string length is >= k, then all the strings are possible

        int n = freq.size();
        // dp.assign(n+1, vector<int>(k+1, -1));  //invalid krne ke liye cnt should be <= k

        // // we have to now find count of invalid strings
        // // invalid strings are the strings which are made by taking instances from each char in original string, and which gives resulting string length < k
        // long long invalidCnt = solve(0, 0, freq, k);

        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        // base case
        for(int cnt = k-1; cnt >= 0; cnt--){
            dp[n][cnt] = 1;
        }

        for(int i = n-1; i >= 0; i--){
            // we can leverage prefix sums/cummulative sum technique to efficiently get the sum between cnt + 1 => cnt + freq[i]
            vector<int> pref(k+1, 0);
            for(int h = 1; h <= k; h++){
                pref[h] = (pref[h-1] + dp[i+1][h-1]) % mod;
            }

            for(int cnt = k-1; cnt >= 0; cnt--){

                int l = cnt + 1;
                int r = cnt + freq[i];

                if(r+1 > k) r = k-1;

                if(l <= r){
                    dp[i][cnt] = (pref[r+1] - pref[l] + mod) % mod;
                }
            }
        }

        long long invalidCnt = dp[0][0];


        return (totalPossible - invalidCnt + mod) % mod;
    }
};