class Solution {
public:
    int solve(vector<pair<int, int>>& o, vector<pair<int, int>>& z, int idx){
        int n = z.size();
        if(idx >= n) return 0;

        int ans = 1e6;
        //try all srcs for current zero cell
        for(int i = 0; i < o.size(); i++){
            if(o[i].first == -1 && o[i].second == -1) continue;  //skip if mark unused

            int curDist = abs(o[i].first - z[idx].first) + abs(o[i].second - z[idx].second);

            auto it = o[i];
            o[i] = {-1, -1};

            ans = min(ans, curDist + solve(o, z, idx+1)); //solved for current zero cell, go and calculate for other zero cells

            o[i] = it;
        }

        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> o, z;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] == 0) z.push_back({i, j});
                else if(grid[i][j] > 1){
                    int extra = grid[i][j] - 1;
                    while(extra--){
                        o.push_back({i, j});
                    }
                }
            }
        }

        return solve(o, z, 0);
    }
};