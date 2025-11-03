class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int maxTime = neededTime[0];
        int consSum = neededTime[0];

        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                consSum += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
            }
            else{
                // jese hi other sequence aa gya, to last sequence me only maximum wala rkh lo(uska cost add nhi hoga, minus krlo total_seq_sum se)    
                ans += (consSum - maxTime);
                maxTime = neededTime[i];
                consSum = neededTime[i];
            }
        }

        // final seq
        ans += (consSum - maxTime);

        return ans;
    }
};

// we need the maximum in each segment of consicutive same color balloons