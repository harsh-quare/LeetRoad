class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // always choose the cell to which we can reach in minimum time
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        int dir[] = {-1,0,1,0,-1};
        while(!pq.empty()){
            int currTime = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == m-1) return currTime;

            for(int i=0; i<4; i++){
                int rNew = r+dir[i];
                int cNew = c+dir[i+1];
                if(rNew < n && cNew < m && rNew >= 0 && cNew >= 0){
                    int newTime = 1 + max(moveTime[rNew][cNew], currTime);

                    if(newTime < time[rNew][cNew]){
                        pq.push({newTime, {rNew,cNew}});
                        time[rNew][cNew] = newTime;
                    }
                }
            }
        }
        return -1;
    }
};