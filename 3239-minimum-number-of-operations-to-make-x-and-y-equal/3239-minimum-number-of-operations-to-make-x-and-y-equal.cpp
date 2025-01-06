class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        // We have different paths to explore and one destination to reach.
        // We need to find minimum distance between src and the destination
        // Use Dijkstra's

        if(y >= x) return y-x;

        unordered_set<int> vis;
        queue<pair<int, int>> q;  //{number, steps}
        q.push({x, 0});
        vis.insert(x);

        while(!q.empty()){
            auto cur = q.front();
            int num = cur.first;
            int steps = cur.second;
            q.pop();

            if(num == y) return steps;

            // path-1: divide by 11, if possible
            if(num % 11 == 0 && vis.find(num / 11) == vis.end()){
                q.push({num/11, steps + 1});
                vis.insert(num / 11);
            }

            if(num % 5 == 0 && vis.find(num / 5 ) == vis.end()){
                q.push({num / 5, steps + 1});
                vis.insert(num / 5);
            }

            if(num - 1 >= 0 && vis.find(num - 1) == vis.end()){
                q.push({num - 1, steps + 1});
                vis.insert(num - 1);
            }

            if(vis.find(num + 1) == vis.end()){
                q.push({num + 1, steps + 1});
                vis.insert(num + 1);
            }
        }

        return -1;
    }
};