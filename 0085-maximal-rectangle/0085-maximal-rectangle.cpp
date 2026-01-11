class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> suf(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = m-1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    cnt++;
                }
                else{
                    cnt = 0;
                }

                suf[i][j] = cnt;
            }
        }

        int area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    int mini = INT_MAX;
                    for(int k = i; k < n; k++){
                        if(matrix[k][j] == '1'){
                            mini = min(mini, suf[k][j]);
                            area = max(area, mini * (k - i + 1));
                        } 
                        else break;
                    }
                }
            }
        }

        return area;
    }
};

// I will consider each 1 as top left corner of rectangle
// I have to precalculate for each 1, how much right I can go