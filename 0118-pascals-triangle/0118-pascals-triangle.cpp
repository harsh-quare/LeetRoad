class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++){
            vector<int> temp(i+1, 1);

            for(int col = 1; col < i; col++){
                temp[col] = ans[i-1][col-1] + ans[i-1][col];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};