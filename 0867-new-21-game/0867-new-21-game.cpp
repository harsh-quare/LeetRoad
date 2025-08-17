class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1);
        dp[0] = 1;

        double currProbSum = (k == 0) ? 0 : 1;

        for(int i = 1; i <= n; i++){
            dp[i] = currProbSum / maxPts;

            if(i < k){
                currProbSum += dp[i];
            }

            if(i - maxPts >= 0 && i-maxPts < k){
                currProbSum -= dp[i - maxPts];
            }
            
        }

        double ans = 0.0;
        for(int i = k; i <= n; i++){
            ans = ans + dp[i];
        }

        return ans;
    }
};