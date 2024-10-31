class Solution {
public:
    long long maxi = 1e16;
    long long solve(int r_id, int f_id, vector<int>& robot, vector<int>& fact, vector<vector<long long>>& dp){
        if(r_id >= robot.size()) return 0;  //all robots have been assigned to factories
        if(f_id >= fact.size()) return maxi;  //No more factories to assign robots to, return a large number to represent infeasibility.

        if(dp[r_id][f_id] != -1) return dp[r_id][f_id];
        
        long long take = abs(robot[r_id] - fact[f_id]) + solve(r_id + 1, f_id + 1, robot, fact, dp);
        long long notTake = solve(r_id, f_id+1, robot, fact, dp);

        return dp[r_id][f_id] = min(take, notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        vector<int> fact_pos;
        for(int i= 0; i < factory.size(); i++){
            int pos = factory[i][0];
            int freq = factory[i][1];
            while(freq--){
                fact_pos.push_back(pos);
            }
        }
        sort(fact_pos.begin(), fact_pos.end());

        vector<vector<long long>> dp(robot.size()+1, vector<long long>(fact_pos.size()+1, -1));

        return solve(0, 0, robot, fact_pos, dp);
    }
};