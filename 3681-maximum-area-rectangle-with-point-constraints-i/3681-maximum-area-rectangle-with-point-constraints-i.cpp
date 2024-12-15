class Solution {
public:
    int findArea(vector<vector<int>>& vp){
        vector<int> bl = vp[0];
        vector<int> tl = vp[1];
        vector<int> br = vp[2];
        vector<int> tr = vp[3];

        if(bl[0] != tl[0] || br[0] != tr[0]) return -1;  //dono sides jo y axis ke parallel h, woh valid h ki nhi
        if(bl[1] != br[1] || tl[1] != tr[1]) return -1;  // dono sides jo x axis ke parallel h, woh valid h ki nahi

        return (abs(br[0] - bl[0]) * abs(bl[1] - tl[1]));
    }

    bool hasPointsBetween(vector<vector<int>>& points, vector<vector<int>>& vp){
        vector<int> bl = vp[0];
        vector<int> tl = vp[1];
        vector<int> br = vp[2];
        vector<int> tr = vp[3];

        for(auto& it: points){
            if(it == bl || it == tl || it == br || it == tr){
                continue;
            }

            if((it[0] >= bl[0] && it[0] <= br[0]) && (it[1] >= bl[1] && it[1] <= tl[1])) return true;
        }

        return false;
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 4) return -1;

        int maxArea = -1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        vector<vector<int>> vp = {points[i], points[j], points[k], points[l]};
                        sort(vp.begin(), vp.end());
                        // sorting will help in getting the four corners of rectangle
                        // first the points will be sorted on x coords, then on y-coords, means 
                        // first pt will be bottom left, then top left, then bottom right, then top right
                        
                        int area = findArea(vp);
                        if(area == -1){
                            continue;
                        }
                        if(hasPointsBetween(points, vp)){
                            continue;
                        }

                        maxArea = max(maxArea, area);
                    }
                }
            }
        }

        return maxArea;
    }
};