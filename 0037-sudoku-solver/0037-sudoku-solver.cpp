class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(i, j, c, board)){
                            board[i][j] = c;
                            if(solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;  //no valid number found, backtrack
                }
            }
        }

        return true;
    }

    bool isValid(int row, int col, char dig, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == dig) return false;
            if(board[i][col] == dig) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == dig) return false;
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // majdoori question
        // backtracking and trying all possible solutions

        solve(board);
    }
};