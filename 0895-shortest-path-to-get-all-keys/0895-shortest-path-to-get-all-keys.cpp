class Solution {
public:
    //BFS
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int x = -1, y = -1;
        int locks = 0;  //locks ka count hoga max lock('a', 'b', 'c', 'd'...) jo milega max, utne hi locks honge
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    x = i;
                    y = j;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f') locks = max(locks, grid[i][j] - 'a' + 1);
            }
        }

        // cout << locks << endl;

        queue<pip> q;
        q.push({0, {x, y}});  //using bitmask for tracking which keys have been received till now
        // 000000: means no lock is there,  000111: means three locks of type-a,b,c are there

        //visited not only depends on x,y but also on the number of keys because we need to move to the same cells if we havan't found the key for a lock
        //so, whenever we found any key, we can traverse entire matrix with that.
        //means there would be three variables for visited {{x,y}, keys}
        //after every key we find, our ability to traverse in the matrix renews itself
        unordered_set<string> vis;
        vis.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            // cout << steps << endl;
            while(sz--){
                auto p = q.front();
                q.pop();

                int keys = p.first;
                int i = p.second.first;
                int j = p.second.second;

                // cout << keys << " " << i << " " << j << endl;

                if(keys == (1 << locks) - 1){  //agar saari keys mil gyi, means saari bits set h
                    return steps;
                }

                for(auto& dir: dirx){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    int branchKeys = keys;  // keys in this branch of BFS

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                        char ch = grid[ni][nj];

                        if(ch == '#') continue;

                        if(ch >= 'a' && ch <= 'f'){
                            // Update keys for this branch of BFS
                            branchKeys |= 1 << (ch - 'a');   // set the bit having this key
                        }

                        if(ch >= 'A' && ch <= 'F' && ((keys >> (ch - 'A')) & 1) == 0){
                            //agar lock pe aa gye and uske liye respective bit wali key set nhi h, to jao or pahle uski key dhundh ke lao
                            //agar chabi nhi h, to skip kr do and pahle key dhundh ke laao or (1 << (ch-'A' )) ko set kro
                            continue ;
                        }
                        //agar current state visited nhi h, to visit kr lo
                        if(!vis.count(to_string(branchKeys) + " " + to_string(ni) + " " + to_string(nj))){
                            vis.insert(to_string(branchKeys) + " " + to_string(ni) + " " + to_string(nj));
                            q.push({branchKeys, {ni, nj}});
                        }
                    }
                }
            }
            steps++;
            // cout << endl;
        }

        return -1;
    }
};