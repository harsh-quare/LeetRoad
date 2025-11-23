class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0;
        int mini1 = INT_MAX, mini11 = INT_MAX;
        int mini2 = INT_MAX, mini22 = INT_MAX;
        for(int x: nums){
            ans += x;
            if(x % 3 == 1) {
                if(x < mini1){
                    mini11 = mini1;
                    mini1 = x;
                }
                else if(x < mini11) mini11 = x;
            }
            else if(x % 3 == 2) {
                if(x < mini2){
                    mini22 = mini2;
                    mini2 = x;
                }
                else if(x < mini22) mini22 = x;
            }
        }

        if(ans % 3 == 0) return ans;
        // if ans % 3 == 1 => remove the minimum guy who has x%3 == 1 or remove 2 guys who have x%3 == 2
        // if ans % 3 == 2 => remove the minimum guy who has x%3 == 2 or remove 2 guys who have x%3 == 1

        if(ans % 3 == 1){
            int p1 = mini1;
            int p2 = (mini2 == INT_MAX || mini22 == INT_MAX) ? INT_MAX : mini2 + mini22;

            return ans - min(p1, p2);
        }
        else{
            int p1 = mini2;
            int p2 = (mini1 == INT_MAX || mini11 == INT_MAX) ? INT_MAX : mini1 + mini11;

            return ans - min(p1, p2);
        }
    }
};