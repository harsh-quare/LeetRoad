class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int mini = 100;
        int maxi1 = -100;
        int maxi2 = -100;

        for(int x: nums){
            if(x > maxi1){
                maxi2 = maxi1;
                maxi1 = x;
            }
            else if(x > maxi2) maxi2 = x;
            if(x < mini){
                mini = x;
            }
            // if(x > maxi2){
            //     maxi2 = x;
            // }
        }

        return maxi1 + maxi2 - mini;
    }
};