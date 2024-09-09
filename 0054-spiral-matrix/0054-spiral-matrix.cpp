class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        int c = n, r = m-1;

        while(ans.size() < m*n){
            for(int l = 0; l < c; l++){
                ans.push_back(matrix[i][j]);
                j++;
            }
            i++;
            j--;
            c--;
            if(ans.size() == m*n) break;

            for(int k = 0; k < r; k++){
                ans.push_back(matrix[i][j]);
                i++;
            }
            i--;
            j--;
            r--;
            if(ans.size() == m*n) break;

            for(int l = 0; l < c; l++){
                ans.push_back(matrix[i][j]);
                j--;
            }
            i--;
            j++;
            c--;
            if(ans.size() == m*n) break;

            for(int k = 0; k < r; k++){
                ans.push_back(matrix[i][j]);
                i--;
            }
            i++;
            j++;
            r--;
            if(ans.size() == m*n) break;
        }


        return ans;
    }
};