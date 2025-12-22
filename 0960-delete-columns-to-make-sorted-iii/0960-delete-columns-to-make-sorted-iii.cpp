class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols = strs[0].size();
        int rows = strs.size();

        vector<int> dp(cols, 1);
        for(int c = 1; c < cols; c++){
            for(int j = 0; j < c; j++){

                bool valid = true;
                for(int r = 0; r < rows; r++){
                    if (strs[r][j] > strs[r][c]){
                        valid = false;
                        break;
                    }
                }

                if(valid){
                    dp[c] = max(dp[c], dp[j] + 1);
                }
            }
        }
        
        return cols - *max_element(dp.begin(), dp.end());
    }
};