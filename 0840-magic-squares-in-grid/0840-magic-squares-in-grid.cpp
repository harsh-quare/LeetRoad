class Solution {
public:
    bool isMagicSquare(int r, int c, vector<vector<int>>& grid){
        //checking for uniqueness and elements between 1 to 9
        unordered_set<int> st;
        for(int i = r; i <= r+2; i++){
            for(int j = c; j <= c+2; j++){
                if(grid[i][j] <= 0 || grid[i][j] >= 10 || st.count(grid[i][j])){
                    return false;
                }
                else{
                    st.insert(grid[i][j]);
                }
            }
        }

        // checking for uniform sum among rows, cols, diags
        int uniformSum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i = 0; i < 3; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != uniformSum) return false;  // checking rows

            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != uniformSum) return false;
        }

        // checking for diagonal and anti diagonal sum
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != uniformSum) return false;
        if(grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2] != uniformSum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(rows <= 2 || cols <= 2) return 0;

        int ans = 0;

        for(int r = 0; r <= rows-3; r++){
            for(int c = 0; c <= cols-3; c++){
                // each {r,c} is the top-left point of the 3x3 square grid

                if(isMagicSquare(r, c, grid)) ans++;
            }
        }

        return ans;
    }
};