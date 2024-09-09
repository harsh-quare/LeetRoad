class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        int val = 1;
        int rowS = 0, rowE = n-1;
        int colS = 0, colE = n-1;
        
        while(val <= n*n){
            for(int i = colS; i <= colE; i++){
                mat[rowS][i] = val++;
            }
            rowS++; //first row done

            for(int i = rowS; i <= rowE; i++){
                mat[i][colE] = val++;
            }
            colE--;

            for(int i = colE; i >= colS; i--){
                mat[rowE][i] = val++;
            }
            rowE--;

            for(int i = rowE; i >= rowS; i--){
                mat[i][colS] = val++;
            }
            colS++;
        }

        return mat;
    }
};