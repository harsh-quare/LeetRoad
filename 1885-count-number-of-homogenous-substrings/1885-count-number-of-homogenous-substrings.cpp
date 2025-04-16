class Solution {
public:
    const int mod = 1e9 + 7;
    int countHomogenous(string s) {
        // every string of length n, whose all the characters are the same, contributes total of n*(n+1)/2 homogenous substrings
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;

        while(j < n){
            if(s[j] != s[i]){
                // the first point when we encounter a new character substring
                int len = j-i;
                long long contrb = 1LL * len * (len + 1) / 2;
                ans = (ans + contrb % mod) % mod;
                i = j;
            }
            j++;
        }

        // the last window/substring
        int len = j-i;
        long long contrb = 1LL * len * (len + 1) / 2;
        ans = (ans + contrb % mod) % mod;

        return ans % mod;
    }
};