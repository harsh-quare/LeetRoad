class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> int_x;
        vector<vector<int>> int_y;

        for(auto& it: rectangles){
            int x1 = it[0];
            int x2 = it[2];

            int y1 = it[1];
            int y2 = it[3];

            int_x.push_back({x1, x2});
            int_y.push_back({y1, y2});
        }

        sort(int_x.begin(), int_x.end());
        sort(int_y.begin(), int_y.end());

        // COunt if there are more than 2 valid cuts available either horizontally or vertically
        int prev_max_x = int_x[0][1];
        int cnt_x = 0;
        for(int i = 1; i < int_x.size(); i++){
            if(prev_max_x <= int_x[i][0]){
                cnt_x++;
            }
            prev_max_x = max(prev_max_x, int_x[i][1]);
        }

        if(cnt_x >= 2) return true;

        int prev_max_y = int_y[0][1];
        int cnt_y = 0;
        for(int i = 1; i < int_y.size(); i++){
            if(prev_max_y <= int_y[i][0]){
                cnt_y++;
            }
            prev_max_y = max(prev_max_y, int_y[i][1]);
        }

        if(cnt_y >= 2) return true;

        return false;
    }
};