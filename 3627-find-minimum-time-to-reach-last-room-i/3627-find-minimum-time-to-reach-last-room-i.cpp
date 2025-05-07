class Solution {
public:
    vector<vector<int>> dirx = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    #define pip pair<int, pair<int, int>> 
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0, 0}});  // start at time = 0, and posn (0, 0)

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;

        while(!pq.empty()){
            int t = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i == n-1 && j == m-1) return t;

            for(auto dir: dirx){
                int nx = i + dir[0];
                int ny = j + dir[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    int newTime = max(t, moveTime[nx][ny]);
                    if(moveTime[nx][ny] <= newTime){
                        vis[nx][ny] = 1;
                        pq.push({newTime+1, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};

// the source is (0,0)
// the destination is (n-1, m-1)
// the grid is of size n*m