class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        return (x >= 0 && x < n && y >= 0 && y < m); 
    }
    int dirx[3] = {-1, 0, 1};
    int getState(int x, int y, vector<vector<int>>& grid){

        int active = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int nx = x + dirx[i];
                int ny = y + dirx[j];

                if(nx == x && ny == y) continue;

                if(isValid(nx, ny, grid) && grid[nx][ny] == 1){
                    active++;
                }
            }
        }

        if(grid[x][y] == 1){
            if(active < 2) return 1;
            else if(active >= 2 && active <= 3) return -1;
            else return 3;
        }
        else{
            if(active == 3) return 4;
            else return -1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<pair<int, int>, int>> flags;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // 1 => live => nbr < 2 => dies
                // 2 => live => nbr = [2,3] => no change 
                // 3 => live => nbr > 3 => dies
                // 4 => dead => nbr == 3 => rebirth
                // -1 => dead => nbr < 3 or nbr > 3 => no change
                int state = getState(i, j, board);
                if(state != -1) flags.push_back({{i, j}, state});
            }
        }

        for(int i = 0; i < flags.size(); i++){
            int x = flags[i].first.first;
            int y = flags[i].first.second;
            int state = flags[i].second;

            if(state == 1 || state == 3) board[x][y] = 0;
            else if(state == 2) continue;
            else if(state == 4) board[x][y] = 1;
        }
    }
};