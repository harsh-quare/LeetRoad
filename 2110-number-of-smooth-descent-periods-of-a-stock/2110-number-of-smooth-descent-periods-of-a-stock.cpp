class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 0;
        int previousPrice = -1;
        int currentStreakLength = 1; // any individual element also a descent period

        for(int price: prices){
            if(previousPrice != -1 && previousPrice - price == 1){
                currentStreakLength += 1;
                result += currentStreakLength;
            }
            else{
                // reset the streak length
                currentStreakLength = 1;
                result += currentStreakLength;
            }

            previousPrice = price;
        }

        return result;
    }
};
