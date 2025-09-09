class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // for each day, from 1 to n. I'll tell the secret to people from [curDay + delay --> curDay + forget - 1]. It will populate the array,
        // and because we need the number of people who know the secret on day n, that will be equal to the number of people from [n-forget+1 --> n

        vector<int> activeGuys(n+1, 0);
        activeGuys[1] = 1;

        for(int i = 1; i <= n; i++){

            for(int j = i + delay; j <= min(n, i+forget-1); j++){

                activeGuys[j] = (activeGuys[j] + activeGuys[i]) % MOD;
            }

        }

        int ans = 0;
        for(int i = n-forget+1; i <= n; i++){
            ans = (ans + activeGuys[i]) % MOD;
        }

        return ans;
    }
};