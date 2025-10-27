class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int r = 0; r < n; r++){
            if(row[r] == 1){
                for(int c = 0; c < m; c++){
                    matrix[r][c] = 0;
                }
            }
        }

        for(int c = 0; c < m; c++){
            if(col[c] == 1){
                for(int r = 0; r < n; r++){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};