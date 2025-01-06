class Solution {
public:
    int racecar(int target) {
        queue<pair<long, long>> q; // {pos, speed}
        q.push({0, 1});
        set<pair<long, long>> vis;
        int lvl = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[pos, sp] = q.front();
                q.pop();

                if(pos == target) return lvl;

                if(vis.find({pos, sp}) != vis.end()) continue;

                // else, explore paths
                else{
                    vis.insert({pos, sp});
                    q.push({pos + sp, sp*2}); // accelerate krte jao, jab tk target na mile

                    // but, agar hamari movement galat h, i.e. agar ham already target se aage kisi position pe h, and positive direction me hi move kr rhe h, to ideally hame reverse krna chahiye
                    // and similarly, agar ham target se piche kisi position pe h and negative direction me, jo ki opposite h jaha hame target milega usse, move kr rhe h, to yaha bhi reverse krke direction positive krni padegi
                    if((pos + sp > target && sp > 0) || (pos + sp < target && sp < 0)){
                        sp = sp > 0 ? -1 : 1;
                        q.push({pos, sp});
                    }
                }
            }
            lvl++;
        }

        return -1;
    }
};