class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;
        int filled = numBottles;

        while(filled){
            ans += filled;
            empty += filled;
            filled = 0;

            if(empty >= numExchange){
                // exchange only one bottle at a time
                empty -= numExchange;
                filled++;
                numExchange++;  // increase numExchange by 1 after each operation
            }
        }

        return ans;
    }
};