class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        long long sum = 0;
        int cnt = 0;
        bool zeroPresent = false;
        int smallest = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0) {
                    cnt++;
                }

                smallest = min(smallest, abs(matrix[i][j]));  // only negative value can be propagated to the smallest absolute value in the matrix

                if(matrix[i][j] == 0) zeroPresent = true;
            }
        }

        return (cnt % 2 == 0 || zeroPresent) ? sum : sum - 2*smallest;
    }
};