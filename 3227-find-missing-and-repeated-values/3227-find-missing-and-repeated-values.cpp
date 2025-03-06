class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n*n+1, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                f[grid[i][j]]++;
            }
        }
        
        int a, b;
        for(int i = 0; i < f.size(); i++){
            if(f[i] == 0) b = i;
            if(f[i] == 2) a = i;
        }

        return {a, b};
    }
};