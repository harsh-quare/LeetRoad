class Solution {
public:
    pair<int, int> solve(int x, int n){  
        // generally, r = x / n, and c = x % n  => when numbers are in left to right and top to bottom
        // but here, the numbers are in bottom to top, and changing direction horizontally after every row, LtoR, RtoL
        int row_from_up = (x-1) / n;
        int row_from_bottom = (n-1) - row_from_up;

        int col = (x-1) % n;

        // if the row is numbered right to left
        if((n % 2 == 0 && row_from_bottom % 2 == 0) || (n % 2 == 1 && row_from_bottom % 2 == 1)) col = (n-1) - col;

        return {row_from_bottom, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if(n == 1) return 0;

        queue<int> q;
        q.push(1);

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n-1][0] = true;

        int steps = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int curr = q.front();
                q.pop();

                if(curr == n*n) return steps;

                // I have total at max 6 options, next 6 cells possible where I can move directly
                for(int i = curr + 1; i <= min(curr + 6, n*n); i++){
                    pair<int, int> coords = solve(i, n);
                    int x = coords.first;
                    int y = coords.second;

                    if(vis[x][y]) continue;
                    
                    vis[x][y] = 1;

                    if(board[x][y] != -1) q.push(board[x][y]);
                    else q.push(i);
                }
            }

            steps++;
        }

        return -1;
    }
};