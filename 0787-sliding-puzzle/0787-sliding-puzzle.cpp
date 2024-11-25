class Solution {
public:
    //the 2d array is flattened to 1d array: because we need the strings to track visited, so ww wiil lose the ability to move in the 2d array, for that I am storing all the possible moves for each index
    vector<vector<int>> dirx = {{1,3}, {0,2,4}, {1,5}, {0,4}, {3,5,1}, {4,2}};  // dirx is the possible directions for exch index, that it can travel to

    int slidingPuzzle(vector<vector<int>>& board) {
        string initState;
        string target = "123450";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                initState += to_string(board[i][j]);
            }
        }

        unordered_set<string> vis;
        queue<string> q;
        q.push(initState);
        vis.insert(initState);
        
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curState = q.front();
                q.pop();

                if(curState == target) return steps;

                int curZeroPos = curState.find('0');

                for(int newPos: dirx[curZeroPos]){   //move to all the possible directions from the currenct zero position
                    string nextState = curState;
                    swap(nextState[curZeroPos], nextState[newPos]);  //nextState me curZeroPos pe jo actual zero position honi chahiye usko daal do

                    if(vis.find(nextState) != vis.end()) continue;  //skip if already visited

                    vis.insert(nextState);
                    q.push(nextState);
                }
            }
            steps++;
        }
        return -1;
    }
};