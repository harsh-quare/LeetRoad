class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        // We have different paths to explore and one destination to reach.
        // We need to find minimum distance between src and the destination
        // Use Dijkstra's

        if(y >= x) return y-x;

        unordered_set<int> vis;
        queue<int> q;
        q.push(x);
        vis.insert(x);
        int ops = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int num = q.front();
                q.pop();

                if(num == y) return ops;

                // path-1: divide by 11, if possible
                if(num % 11 == 0 && vis.find(num / 11) == vis.end()){
                    q.push(num / 11);
                    vis.insert(num / 11);
                }

                // path-2: divide by 5, if possible
                if(num % 5 == 0 && vis.find(num / 5) == vis.end()){
                    q.push(num / 5);
                    vis.insert(num / 5);
                }

                // decrement by 1, if inside bounds
                if(num - 1 >= 0 && vis.find(num - 1) == vis.end()){
                    q.push(num - 1);
                    vis.insert(num - 1);
                }

                // increment by 1
                if(vis.find(num + 1) == vis.end()){
                    q.push(num + 1);
                    vis.insert(num + 1);
                }
            }
            ops++;
        }

        return -1;
    }
};