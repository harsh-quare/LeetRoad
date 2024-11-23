class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> rotated(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rotated[i][j] = box[m-j-1][i];
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(rotated[i][j] == '.'){
                    //go up and if u have any stone, put it in this empty space, if not obstacled by another stone or block
                    for(int l = i; l >= 0; l--){
                        if(rotated[l][j] == '*') break;
                        else if(rotated[l][j] == '#'){
                            rotated[i][j] = '#';
                            rotated[l][j] = '.';  //empty the cell from where stone was taken
                            break;
                        }
                    }
                }
            }
        }

        return rotated;
    }
};