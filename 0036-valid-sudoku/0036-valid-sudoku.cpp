class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<vector<int>> rowDigFreq(n, vector<int>(10, 0));
        vector<vector<int>> colDigFreq(n, vector<int>(10, 0));
        vector<vector<int>> subBoxFreq(n, vector<int>(10, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int dig = board[i][j] - '0';

                    if(rowDigFreq[i][dig] != 0 || colDigFreq[j][dig] != 0) return false;
                    rowDigFreq[i][dig] = 1;
                    colDigFreq[j][dig] = 1;

                    int subX = i / 3;
                    int subY = j / 3;
                    int idx = subX * 3 + subY;

                    if(subBoxFreq[idx][dig] != 0) return false;
                    subBoxFreq[idx][dig] = 1;
                }
            }
        }
        return true;
    }
};