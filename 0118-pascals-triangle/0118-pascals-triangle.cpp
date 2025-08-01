class Solution {
public:
    vector<int> generateRow(int n){
        vector<int> vec;
        vec.push_back(1);
        long long res = 1;
        for(int col = 1; col < n; col++){
            res = res * (n - col);
            res = res / col;

            vec.push_back(res);
        }

        return vec;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++){
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};