class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones_left = 0;
        int ans = INT_MIN;
        int zeros_left = 0;
        for(int i = 0; i <= n-2; i++){
            if(s[i] == '1') ones_left++;
            else zeros_left++;

            ans = max(ans, zeros_left - ones_left);
        }

        if(s[n-1] == '1') ones_left++;   //now this is total number of zeros

        int total_ones = ones_left;
        return ans + total_ones;
    }
};

// O_total = O_right + O_left
// O_right = O_total - O_left

// ans = Z_left + O_right
// ans = (Z_left - O_left) + O_total

// O_total is constant, we will add this at end
// Maintain O_left and Z_left