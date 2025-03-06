class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqSum = 0;
        long long n = grid.size();
        long long total = n*n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
                sqSum += static_cast<long long>(grid[i][j]) * grid[i][j];
            }
        }

        // expected sum => n*(n+1)/2
        // expected sqSum = n*(n+1)*(2*n+1)/6

        long long sumDiff = sum - total*(total+1) / 2;
        long long sqrDiff = sqSum - total*(total+1)*(2*total + 1) / 6;

        // sumDiff = x-y
        // sqrDiff = x² - y²

        int rep = (sqrDiff/sumDiff + sumDiff) / 2;
        int mis = (sqrDiff/sumDiff - sumDiff) / 2;

        return {rep, mis};
    }
};