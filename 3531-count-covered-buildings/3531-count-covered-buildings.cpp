class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> mpY;
        unordered_map<int, vector<int>> mpX;
        map<pair<int, int>, int> eligibles;

        for(auto& b: buildings){
            int x = b[0];
            int y = b[1];
            mpY[y].push_back(x);

            mpX[x].push_back(y);
        }

        for(auto& [y, vec]: mpY){
            if(vec.size() > 2){
                sort(vec.begin(), vec.end());
                for(int i = 0; i < vec.size(); i++){
                    if(i == 0 || i == vec.size() - 1){
                        continue;
                    }
                    else{
                        int x = vec[i];
                        eligibles[{x, y}]++;
                    }
                }
            }
        }
        for(auto& [x, vec]: mpX){
            if(vec.size() > 2){
                sort(vec.begin(), vec.end());
                for(int i = 0; i < vec.size(); i++){
                    if(i == 0 || i == vec.size() - 1){
                        continue;
                    }
                    else{
                        int y = vec[i];
                        eligibles[{x, y}]++;
                    }
                }
            }
        }


        int cnt = 0;
        for(auto& [p, freq]: eligibles){
            if(freq == 2) cnt++;
        }

        return cnt;
    }
};


// mp1 => for each 'y' => store all the points
// mp2 => for each 'x' => store all the points

// eligibles => {{x,y},...}


// [[2,1],[2,3],[3,3],[2,2],[1,3]]

// mpY => {1: {2}, 2: {2}, 3: {1,2,3}} 
// mpX => {1: {3}, 2: {1,2,3}, 3: {3}}

// eligibles => {{2,3}: 1, {2,2}: 1}