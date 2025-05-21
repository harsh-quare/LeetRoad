class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int col0 = 1;
        
        // step-1: mark 1st row and col
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    if(j != 0) mat[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        // step-2: marking in (1,1) to (n-1, m-1)
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] != 0){
                    if(mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
                }
            }
        }

        // 1st row marking
        if(mat[0][0] == 0){
            for(int j = 0; j < m; j++) mat[0][j] = 0;
        }

        // 1st col marking
        if(col0 == 0){
            for(int i = 0; i < n; i++) mat[i][0] = 0;
        }
    }
};