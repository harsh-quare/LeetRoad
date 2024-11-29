class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumTime(vector<vector<int>>& grid) {
        //Dijkstra's

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0, 0}});  //time and coords
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;

        while(!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1) return t;

            bool flag = true;  //will indicate that iss cell ke paas kam se kam ek cell to aisi h jispe ye ja skta h, ya nhi
            // basically example-2 me 0,0 se kahi nhi ja skte, usko detect krne ke liye hi ye check h

            for(auto& dir: dirx){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int next_time = t + 1;  //moving takes exactly 1 second

                    //check if the next cell is accessible
                    if(next_time >= grid[nx][ny]){
                        //push the state if it improves the shortest time
                        if(next_time < dist[nx][ny]){
                            dist[nx][ny] = next_time;
                            pq.push({next_time, {nx, ny}});
                        }
                        flag = false; // yes, koi ek bnda to h, jiske paas ja skte h
                    } 
                    //if the cell is not accessible, time needs to pass
                    else{
                        //calculate the earliest valid time we can enter
                        int wait_time = grid[nx][ny] - next_time;
                        
                        //ensure valid parity (alternating movement)
                        if(wait_time % 2 != 0) wait_time++;

                        int adjusted_time = next_time + wait_time;

                        if(adjusted_time < dist[nx][ny]){
                            dist[nx][ny] = adjusted_time;
                            pq.push({adjusted_time, {nx, ny}});
                        }
                    }
                }
            }

            if(flag == true) return -1;
        }
        
        return -1;
    }
};