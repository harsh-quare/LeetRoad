class Solution {
public:
    // int getLcsAscii(int i, int j, string& s1, string& s2, int n, int m, vector<vector<int>>& dp){
    //     if(i >= n || j >= m) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int lcsAscii = 0;
        
    //     // if both chars are same, get the ascii of current and solve for remaining part
    //     if(s1[i] == s2[j]){
    //         lcsAscii = s1[i] + getLcsAscii(i+1, j+1, s1, s2, n, m, dp);
    //     }
    //     else{
    //         lcsAscii = max(getLcsAscii(i+1, j, s1, s2, n, m, dp), getLcsAscii(i, j+1, s1, s2, n, m, dp));
    //     }

    //     return dp[i][j] = lcsAscii;
    // }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        int totalAscii = 0;
        for(char c: s1) totalAscii += c;
        for(char c: s2) totalAscii += c;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int lcsAscii = 0;
                
                // if both chars are same, get the ascii of current and solve for remaining part
                if(s1[i] == s2[j]){
                    lcsAscii = s1[i] + dp[i+1][j+1];
                }
                else{
                    lcsAscii = max(dp[i+1][j], dp[i][j+1]);
                }

                dp[i][j] = lcsAscii;
            }
        }

        int lcsAscii = dp[0][0];  // maximizing the ascii of a common subseq => find lcs

        return totalAscii - 2*lcsAscii;
    }
};