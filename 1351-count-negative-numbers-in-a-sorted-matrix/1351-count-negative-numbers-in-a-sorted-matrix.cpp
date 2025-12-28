class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        int x = n-1, y = 0;
        while(x >= 0 && y < m){
            if(grid[x][y] >= 0){
                // there might be negative values to the right of it => go and check
                y++;
            }
            else{
                // found negative, that means all the values are negative to its right, bcz array sorted in non decreasing order
                cnt += m - y;  // count all the elements to its right, this row is done
                x--;  // move to previous row
            }
        }

        return cnt;
    }
};

// 4  3  2  -1
// 3  2  1  -1
// 1  1 -1  -2
//-1 -1 -2  -3 