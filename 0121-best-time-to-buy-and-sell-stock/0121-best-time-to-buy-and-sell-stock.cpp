class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int mini = prices[0];

        for(int i = 0; i < prices.size(); i++){
            int cur = prices[i] - mini;
            maxProf = max(maxProf, cur);
            mini = min(mini, prices[i]);
        } 

        return maxProf;
    }
};