class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        deque<int> dq;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){
            while(!dq.empty() && prices[i] < prices[dq.back()]){
                dq.pop_back();
            }

            if(!dq.empty()){
                ans[i] = prices[i] - prices[dq.back()];
            }
            else{
                ans[i] = prices[i];
            }

            dq.push_back(i);
        }

        return ans;
    }
};