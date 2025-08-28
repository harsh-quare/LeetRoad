class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // will store vector of each diagonal. we identify each diagonal by 
        // it's (i-j) value => for simplicity and avoiding runtime error in vectors => we use (i-j + n-1)
        map<int, vector<int>> helper;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int idx = i-j;
                helper[idx].push_back(grid[i][j]);
            }
        }

        // Sort values in each diagonal acc to the requirements of the problem
        // But we don't want extra space in storing the pointers of each diagonal during updating the grid
        // so we sort both the triangle diagonals in opposite way
        // so that we can traverse from back of the array and pop elements on the go
        for(auto& [idx, vec]: helper){
            if(idx >= 0){  // bottom left diagonal
                sort(helper[idx].begin(), helper[idx].end());
            }
            else{
                sort(helper[idx].begin(), helper[idx].end(), greater<int>());
            }
        }

        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int idx = i-j;
                grid[i][j] = helper[idx].back();
                helper[idx].pop_back();
            }
        }

        return grid;
    }
};