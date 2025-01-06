class Solution {
public:
    int solve(vector<pair<int, int>>& src, vector<pair<int, int>>& dest, int idx){
        int n = dest.size();
        if(idx == n){
            return 0; //all destinations are processed
        }

        int ans = 1e8;

        //try all sources for the current destination
        for(int i = 0; i < src.size(); i++){
            if(src[i].first == -1 && src[i].second == -1){
                continue; // Skip already used sources
            }

            int curDistance = abs(dest[idx].first - src[i].first) + abs(dest[idx].second - src[i].second);

            //temporarily mark this source as used
            auto temp = src[i];
            src[i] = {-1, -1};

            //recurse for the next destination
            ans = min(ans, curDistance + solve(src, dest, idx + 1));

            //restore the source for backtracking
            src[i] = temp;
        }

        return ans;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> sources, dest;

        //extract sources and destinations from the grid
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] == 0){
                    dest.push_back({i, j}); //deficit cells
                } 
                else if(grid[i][j] > 1){
                    int extra = grid[i][j] - 1;
                    while (extra--){
                        sources.push_back({i, j}); //surplus cells
                    }
                }
            }
        }

        return solve(sources, dest, 0);
    }
};
