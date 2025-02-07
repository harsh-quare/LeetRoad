class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n);

        unordered_map<int, int> balls;
        unordered_map<int, int> colors;

        for(int i = 0; i < n; i++){
            int ball = queries[i][0];
            int clr = queries[i][1];

            if(balls[ball] == 0){
                balls[ball] = clr;
                colors[clr]++;
            }
            else{
                int prevClr = balls[ball];
                // remove prev color
                colors[prevClr]--;
                if(colors[prevClr] == 0) colors.erase(prevClr);

                //update new
                balls[ball] = clr;
                colors[clr]++;
            }

            res[i] = colors.size();
        }

        return res;
    }
};