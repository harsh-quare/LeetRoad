class Solution {
public:
    pair<int, int> slope_form(int x1, int y1, int x2, int y2){
        int dx = x1-x2;
        int dy = y1-y2;

        if(dx < 0){
            dx *= -1;
            dy *= -1;
        }

        if(dx == 0) return {0, 1};  // parellel to y
        if(dy == 0) return {1, 0};  // parellel to x

        int g = gcd(abs(dx), abs(dy));

        return {dx/g, dy/g};
    }
    int countTrapezoids(vector<vector<int>>& points) {
        map<pair<int, int>, map<int, int>> mp;  // {slope, {intercept, cnt}}
        map<pair<int, int>, int> mids;
        map<pair<int, int>, map<pair<int, int>, int>> mid_diff;

        int prllgram = 0;
        for(int i = 0; i < int(points.size()); i++){
            for(int j = i+1; j < int(points.size()); j++){
                auto slope = slope_form(points[i][0], points[i][1], points[j][0], points[j][1]);
                int intercept = slope.second * points[i][0] - slope.first * points[i][1];
                mp[slope][intercept]++;

                // check for prllgram
                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];

                // same midpoint but different slope
                prllgram += (mids[{mx, my}] - mid_diff[{mx, my}][slope]);
                mids[{mx, my}]++;
                mid_diff[{mx, my}][slope]++;
            }
        }

        int ans = 0;
        for(auto& [slope, vals]: mp){
            int tot = 0, sum = 0;
            for(auto& [intercept, cnt]: vals){
                sum += cnt * tot;
                tot += cnt;
            }
            ans += sum;
        }

        ans -= prllgram;

        return ans;
    }
};