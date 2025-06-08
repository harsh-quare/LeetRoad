class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int trade1BuyPrice = INT_MAX;
        int trade2BuyPrice = INT_MAX;
        int trade1Profit = 0;
        int trade2Profit = 0;

        for(auto price : prices){
            trade1BuyPrice = min(trade1BuyPrice, price);
            trade1Profit = max(trade1Profit, price - trade1BuyPrice);

            trade2BuyPrice = min(trade2BuyPrice, price - trade1Profit);
            trade2Profit = max(trade2Profit, price - trade2BuyPrice);
        }

        return trade2Profit;
    }
};