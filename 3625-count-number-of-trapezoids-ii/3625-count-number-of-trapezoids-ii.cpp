class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        // y = mx + c
        // now we need two things to uniquely identify a line => {slope, intercept}

        int n = points.size();

        map<float, vector<float>> slopeIntercepts;   // {s1 => {y1, y1, y1, y2, y3, y3}} => s1 slope ke liye, y1 intercept wali 3 lines, y2 wali 1 and y3 wali 2 lines h. => ans = 0*3 + 3*1 + 4*2

        unordered_map<int, vector<float>> midpointSlopes;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                float slope, intercept;
                if(dx == 0){
                    slope = 1e9 + 7;
                    intercept = x1; // or x2, bcz x1 == x2
                }
                else{
                    slope = (float)dy/dx;
                    intercept = (float)(y1*dx - x1*dy) / dx;
                }

                int midX = x1 + x2, midY = y1 + y2;
                int midpoint = midX*10000 + midY;

                slopeIntercepts[slope].push_back(intercept);
                midpointSlopes[midpoint].push_back(slope);
            }
        }

        int ans = 0;
        for(auto& [slope, intercepts]: slopeIntercepts){

            unordered_map<float, int> interceptCount;
            for(auto &intcpt: intercepts){
                interceptCount[intcpt]++;
            }

            int prevSameSlopeLines = 0;
            for(auto& [intcpt, freq]: interceptCount){
                ans += prevSameSlopeLines * freq;  // it's counting duplicates also, when 2 pair of parellel lines are in single trapezoid(i.e. parallelogram)
                prevSameSlopeLines += freq;
            }
        }

        // remove the number of lines having same midPoint (i.e. => remove the number of parallelograms) from total count
        for(auto& [midpoint, slopes]: midpointSlopes){

            unordered_map<float, int> slopeCnt;
            for(auto& slope: slopes){
                slopeCnt[slope]++;
            }

            int prevSameSlopeLines = 0;
            for(auto& [slope, freq]: slopeCnt){
                ans -= prevSameSlopeLines * freq;
                prevSameSlopeLines += freq;
            }
        }

        return ans;
    }
};