class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        // bfs
        // go to the available box, take its candies, go to all the keys it contains, and add them to the queue, go to it's containedBoxes, and add the ones in the queue which are open and not visited earlier

        int ans = 0;
        queue<int> q;
        vector<int> vis(n, 0);
        unordered_set<int> locked_boxes;
        unordered_set<int> have_keys;

        for(int x: initialBoxes){
            if(vis[x]) continue;
            if(status[x] == 1 || have_keys.count(x)) {
                ans += candies[x];
                vis[x] = 1;
                q.push(x);
            }
            else{
                locked_boxes.insert(x);
            }
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();

            for(int newBox : containedBoxes[box]){
                if(vis[newBox]) continue;
                if(status[newBox] == 1 || have_keys.count(newBox)){
                    ans += candies[newBox];
                    vis[newBox] = 1;
                    q.push(newBox);
                } 
                else{
                    locked_boxes.insert(newBox);
                }
            }

            // keys[box] me jitni bhi keys h, unko store krlo and check krlo unn keys labels wale boxes ko, ki woh pahle kahi mile h hame locked and not visited??
            for(int k : keys[box]) {
                have_keys.insert(k);
                if(locked_boxes.count(k) && !vis[k]){
                    ans += candies[k];
                    vis[k] = 1;
                    q.push(k);
                    locked_boxes.erase(k);
                }
            }
        }

        return ans;
    }
};