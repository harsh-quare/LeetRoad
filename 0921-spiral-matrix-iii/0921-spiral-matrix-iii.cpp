class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // 1r, 1d, 2l, 2u, 3r, 3d, 4l, 4u, 5r, 5d...
        vector<vector<int>> ans;
        int total = rows*cols;
        int cnt = 1;
        ans.push_back({rStart, cStart});
        int i = rStart, j = cStart;

        int steps = 1;

        while(cnt < total){
            //right
            for(int r = 0; r<steps; r++){
                j++;
                if(j < cols && j >= 0 && i < rows && i >= 0){
                    ans.push_back({i, j});
                    cnt++;
                }
            }

            //neeche
            for(int d = 0; d<steps; d++){
                i++;
                if(j < cols && j >= 0 && i < rows && i >= 0){
                    ans.push_back({i, j});
                    cnt++;
                }
            }

            //2 directions done, Now steps in each direxn will be more, increment by 1
            steps++;
            
            //left
            for(int l = 0; l <steps; l++){
                j--;
                if(j < cols && j >= 0 && i < rows && i >= 0){
                    ans.push_back({i, j});
                    cnt++;
                }
            }

            //up
            for(int u = 0; u<steps; u++){
                i--;
                if(j < cols && j >= 0 && i < rows && i >= 0){
                    ans.push_back({i, j});
                    cnt++;
                }
            }

            //Another 2 directions done, Now steps in each direxn will be more, increment by 1
            steps++;
        }

        return ans;
    }
};