class Solution {
public:
    #define pip pair<int, pair<int, int>>
    vector<vector<int>> dirx = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int x = -1, y = -1;  //starting point
        int locks = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ch = grid[i][j];
                if(ch == '@'){
                    x = i, y = j;
                }

                if(ch >= 'a' && ch <= 'f'){
                    locks = max(locks, ch - 'a' + 1);
                }
            }
        }

        queue<pip> q;
        q.push({0, {x, y}});

        

        //there will be three states in the visited, bcz whenever we get a key, we renew our ability to traverse the entire matrix
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>((1 << locks) + 1, false)));
        vis[x][y][0] = true;

        // cout << (1 << locks) << endl;

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            // cout << steps << endl;
            while(sz--){
                int keys = q.front().first;
                int i = q.front().second.first;
                int j = q.front().second.second;
                q.pop();

                // cout << keys << " " << i << " " << j << endl;

                if(keys == ((1 << locks) - 1)){  //all bits set??
                    return steps;
                }

                for(auto& dir: dirx){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    int BFSbranchKeys = keys;

                    if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                        
                        char ch = grid[ni][nj];

                        if(ch == '#') continue;

                        if(ch >= 'a' && ch <= 'f'){
                            //pick up the key, set the respective bit
                            BFSbranchKeys |= (1 << (ch-'a'));
                        }

                        if(ch >= 'A' && ch <= 'F'){
                            //if you don't have the key for this lock, just continue your journey and chabi dhundh ke lao, fir aake baat krna
                            if(((keys >> (ch - 'A')) & 1) == 0){
                                continue;
                            }
                        }

                        if(!vis[ni][nj][BFSbranchKeys]){
                            vis[ni][nj][BFSbranchKeys] = true;
                            q.push({BFSbranchKeys, {ni, nj}});
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