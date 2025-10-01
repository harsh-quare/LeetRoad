class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int empty = 0;

        int ans = 0;
        while(filled){
            ans += filled;
            empty += filled;
            filled = 0;

            if(empty >= numExchange){
                filled += empty / numExchange;
                empty = empty % numExchange;
            }
        }

        return ans;
    }
};