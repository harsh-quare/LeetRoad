class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> mpY;
        map<int, set<int>> mpX;

        for(auto& b: buildings){
            int x = b[0];
            int y = b[1];
            mpY[y].insert(x);

            mpX[x].insert(y);
        }

        map<pair<int, int>, int> eligibles;

        for(auto& [y, st]: mpY){
            if(st.size() > 2){
                for(auto it = st.begin(); it != st.end(); it++){
                    if(it == st.begin() || it == prev(st.end())){
                        continue;
                    }
                    else{
                        int x = *it;
                        eligibles[{x, y}]++;
                    }
                }
            }
        }
    
        for(auto& [x, st]: mpX){
           
            if(st.size() > 2){
                for(auto it = st.begin(); it != st.end(); it++){
                    if(it == st.begin() || it == prev(st.end())){
                        continue;
                    }
                    else{
                        int y = *it;
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