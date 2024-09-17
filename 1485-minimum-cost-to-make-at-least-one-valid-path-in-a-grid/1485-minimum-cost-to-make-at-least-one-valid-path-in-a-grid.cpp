class Solution {
public:
bool isValid(int x, int y, int n, int m){
    if(x >= 0 and x < n and y >= 0 and y < m) return true;
    return false;
}
    int minCost(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int dp[n+1][m+1];
        int ct = 1;

        memset(dp , 10000, sizeof(dp));
        dp[0][0] = 0;
        queue<pair<int,int>> p;
        p.push({0,0});
        vector<pair<int, int>> dir {{0, 1}, {0, -1}, {1, 0},{-1, 0}};
        while(!p.empty()){
            pair<int,int> point = p.front();
            p.pop();
            int x = point.first , y = point.second ;
            ct++;
            for(int i=0 ; i<4 ; i++){
                int X = x + dir[i].first , Y = y + dir[i].second;
                if(isValid( X , Y ,n ,m )){
                    if(i + 1 == g[x][y] and dp[X][Y] > dp[x][y]){
                        dp [ X][Y]= dp[x][y];
                        p.push({X, Y});
                    }        
                    else if(dp[X][Y] > dp[x][y] +1){
                        dp [X][Y]= dp[x][y] +1;
                        p.push({X, Y});
                    }
                }
            }
        }
        return dp [n -1][m -1];
    }
};