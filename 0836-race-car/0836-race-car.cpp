class Solution {
public:
    int racecar(int target) {
        queue<pair<long long, long long>> q; // {pos, speed}
        q.push({0, 1});
        set<pair<long long, long long>> vis;
        vis.insert({0, 1});
        int lvl = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[pos, sp] = q.front();
                q.pop();

                if(pos == target) return lvl;

                // explore paths
                if(pos + sp <= 2 * target && vis.find({pos + sp, sp*2}) == vis.end()){
                    // pos + sp <= 2 * target, ensures that we don't consider positions that are far beyond target
                    q.push({pos + sp, sp*2});
                    vis.insert({pos + sp, sp*2});
                }

                if(sp > 0 && vis.find({pos, -1}) == vis.end()){
                    q.push({pos, -1});
                    vis.insert({pos, -1});
                }
                else if(sp < 0 && vis.find({pos, 1}) == vis.end()){
                    q.push({pos, 1});
                    vis.insert({pos, 1});
                }
            }
            lvl++;
        }

        return -1;
    }
};