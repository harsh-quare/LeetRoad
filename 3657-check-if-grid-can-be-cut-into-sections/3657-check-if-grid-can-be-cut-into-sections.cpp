class Solution {
public:
    bool solve(vector<vector<int>>& rectangles, int dim){
        int gaps = 0;

        sort(rectangles.begin(), rectangles.end(),
            [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
            });

        int prev_max_end = rectangles[0][dim + 2];

        for(int i = 1; i < rectangles.size(); i++){
            vector<int>& rect = rectangles[i];

            if(prev_max_end <= rect[dim]){
                gaps++;
            }

            prev_max_end = max(prev_max_end, rect[dim + 2]);
        }

        return gaps >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return solve(rectangles, 0) || solve(rectangles, 1);
    }
};