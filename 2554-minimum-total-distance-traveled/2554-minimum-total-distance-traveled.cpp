class Solution {
public:
    // long long maxi = 1e16;
    // long long solve(int r_id, int f_id, vector<int>& robot, vector<int>& fact, vector<vector<long long>>& dp){
    //     if(r_id >= robot.size()) return 0;  //all robots have been assigned to factories
    //     if(f_id >= fact.size()) return maxi;  //No more factories to assign robots to, return a large number to represent infeasibility.

    //     if(dp[r_id][f_id] != -1) return dp[r_id][f_id];
        
    //     long long take = abs(robot[r_id] - fact[f_id]) + solve(r_id + 1, f_id + 1, robot, fact, dp);
    //     long long notTake = solve(r_id, f_id+1, robot, fact, dp);

    //     return dp[r_id][f_id] = min(take, notTake);
    // }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        sort(robot.begin(), robot.end());
        vector<int> fact_pos;
        for(int i= 0; i < factory.size(); i++){
            int pos = factory[i][0];
            int freq = factory[i][1];
            while(freq--){
                fact_pos.push_back(pos);
            }
        }
        int m = fact_pos.size();
        sort(fact_pos.begin(), fact_pos.end());

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

        //base case
        for(int i = 0; i < n; i++){
            dp[i][m] = 1e12; // no factories left
        }

        //fill dp table bottom-up
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                //op-1: assign current robot to current factory
                long long take = abs(robot[i] - fact_pos[j]) + dp[i+1][j+1];

                //op-2: skip current factory for current robot
                long long notTake = dp[i][j+1];

                dp[i][j] = min(take, notTake);
            }
        }

        return dp[0][0];
    }
};