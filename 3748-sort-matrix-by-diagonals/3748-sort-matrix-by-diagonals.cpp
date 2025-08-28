class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> helper(2*n);  // will store vector of each diagonal. we identify each diagonal by it's (i-j) value => for simplicity and avoiding runtime error in vectors => we use (i-j + n-1)

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int idx = i-j + n-1;
                helper[idx].push_back(grid[i][j]);
            }
        }

        // Sort values in each diagonal acc to the requirements of the problem
        for(int idx = 0; idx < 2*n; idx++){
            if(idx >= n-1){  // bottom left diagonal => non-increasing
                sort(helper[idx].begin(), helper[idx].end(), greater<int>());
            }
            else{
                sort(helper[idx].begin(), helper[idx].end());
            }
        }

        // we need pointer for each diagonal => bcz we need to know which value to put if certain diagonal is met
        vector<int> ptrs(2*n, 0);  // index is representing diagonal, value is representing the index of pointer in the diagonal array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int idx = i-j + n-1;
                int curPtr = ptrs[idx];

                grid[i][j] = helper[idx][curPtr];
                ptrs[idx] = curPtr + 1;
            }
        }

        return grid;
    }
};