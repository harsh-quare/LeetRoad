class Solution {
public: 
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0,0}});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;

        while(!pq.empty()){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return time;

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    int newTime = max(time, moveTime[nx][ny]);
                    if(newTime >= moveTime[nx][ny]){
                        if((nx + ny) % 2 != 0){
                            pq.push({newTime + 1, {nx, ny}});
                            vis[nx][ny] = 1;
                        }
                        else{
                            pq.push({newTime + 2, {nx, ny}});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};