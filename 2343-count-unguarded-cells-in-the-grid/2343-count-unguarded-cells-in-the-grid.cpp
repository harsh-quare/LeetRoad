class Solution {
public:
    void goUp(int i, int j, int m, int n, vector<vector<int>>& grid){
        i--;  //start from just above cell
        while(i >= 0){
            if(grid[i][j] == 2 || grid[i][j] == 1){
                break;
            }
            else{
                grid[i][j] = -1;
            }
            i--;
        }
    }
    void goDown(int i, int j, int m, int n, vector<vector<int>>& grid){
        i++;  //start from just below cell
        while(i < m){
            if(grid[i][j] == 2 || grid[i][j] == 1){
                break;
            }
            else{
                grid[i][j] = -1;
            }
            i++;
        }
    }

    void goLeft(int i, int j, int m, int n, vector<vector<int>>& grid){
        j--;  //start from just left cell
        while(j >= 0){
            if(grid[i][j] == 2 || grid[i][j] == 1){
                break;
            }
            else{
                grid[i][j] = -1;
            }
            j--;
        }
    }

    void goRight(int i, int j, int m, int n, vector<vector<int>>& grid){
        j++;  //start from just right cell
        while(j < n){
            if(grid[i][j] == 2 || grid[i][j] == 1){
                break;
            }
            else{
                grid[i][j] = -1;
            }
            j++;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));  //initially consider evry cell as unguarded
        for(auto& g: guards){
            grid[g[0]][g[1]] = 1;  //guard
        }
        for(auto& w: walls){
            grid[w[0]][w[1]] = 2;  //wall
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    //up, down, left, right
                    //and mark guarded whichever are guarded by a guard
                    goUp(i, j, m, n, grid);
                    goDown(i, j, m, n, grid);
                    goLeft(i, j, m, n, grid);
                    goRight(i, j, m, n, grid);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};