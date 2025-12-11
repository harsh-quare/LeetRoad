class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int, int>> vecY(n+1, {INT_MAX, INT_MIN});
        vector<pair<int, int>> vecX(n+1, {INT_MAX, INT_MIN});

        for(auto& b: buildings){
            int x = b[0];
            int y = b[1];
            
            vecY[y].first = min(x, vecY[y].first);
            vecY[y].second = max(x, vecY[y].second);

            vecX[x].first = min(y, vecX[x].first);
            vecX[x].second = max(y, vecX[x].second);
        }

        int cnt = 0;
        for(auto b: buildings){
            int x = b[0];
            int y = b[1];

            int miniY = vecX[x].first;
            int maxiY = vecX[x].second;

            int miniX = vecY[y].first;
            int maxiX = vecY[y].second;

            if(y > miniY && y < maxiY && x > miniX && x < maxiX) cnt++;
        }

        return cnt;

    }
};