class Solution {
public:
    // long long solve(int ida, int idb, vector<int>& a, vector<int>& b, vector<vector<long long>>& dp){
    //     if(ida >= 4) return 0;
    //     if(idb == b.size()-1){
    //         if(ida == 3) return (long long)a[ida]*b[idb];
    //         else return -1e14;
    //     }

    //     if(dp[ida][idb] != -1) return dp[ida][idb];


    //     long long notTake = solve(ida, idb+1, a, b, dp);
    //     long long take = (long long)a[ida]*b[idb] + solve(ida+1, idb+1, a, b, dp);

    //     return dp[ida][idb] = max(take, notTake);
    // }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        int m = a.size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, -1e14));

        //base case: all elements of a are used
        for(int i = 0; i <= n; i++){
            dp[m][i] = 0; //ida >= 4: return 0
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                long long notTake = dp[i][j+1];

                long long take = -1e14;
                if(i <= 3 && j <= n-1){
                    take = (long long)a[i]*b[j] + dp[i+1][j+1];
                }

                dp[i][j] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};