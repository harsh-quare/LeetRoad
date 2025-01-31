class Solution {

private:

    bool isValid(int x,int y, vector<vector<int>>& grid){
        int n = grid.size();
        if(x>=0 && x<n && y>=0 && y<n){return true;}
        return false;
    }

    void dfs(int x,int y, vector<vector<int>>& grid, vector<vector<int>>& color,int &area, int cur){
        ++area;
        color[x][y]=cur;
        vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &dir:dirs){
            int new_x = x+dir[0];
            int new_y = y+dir[1];
            if(isValid(new_x,new_y,grid) && grid[new_x][new_y]==1 && color[new_x][new_y]==-1){
                dfs(new_x,new_y,grid,color,area,cur);
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>color(n,vector<int>(n,-1));
        vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int cur = 0;
        vector<int>mpp;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1 && color[i][j]==-1){
                    int area = 0;
                    dfs(i,j,grid,color,area,cur);
                    mpp.push_back(area);
                    ++cur;
                }
            }
        }
        int ans = mpp.empty() ? 0 : *max_element(mpp.begin(), mpp.end());
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    set<int>s;
                    int temp_area = 1;
                    for(auto&dir:dirs){
                        int new_x = i+dir[0];
                        int new_y = j+dir[1];
                        if(isValid(new_x,new_y,grid) && grid[new_x][new_y]==1 && s.find(color[new_x][new_y])==s.end()){
                            s.insert(color[new_x][new_y]);
                            temp_area+=mpp[color[new_x][new_y]];
                        }
                    }
                    ans=max(ans,temp_area);
                }
            }
        }
        return ans;
    }
};