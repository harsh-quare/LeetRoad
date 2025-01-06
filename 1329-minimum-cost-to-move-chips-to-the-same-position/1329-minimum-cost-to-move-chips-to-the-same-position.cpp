class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // there are only two positions, if we break down the problem statement, 0 and 1, because we are doing modulo with 2

        int zeroCnt = 0;
        int oneCnt = 0;
        for(int i = 0; i < position.size(); i++){
            if(position[i] % 2 == 0) zeroCnt++;
            else oneCnt++;
        }

        // Only cost we will be having will be to move coins from 1 to 0 or from 0 to 1 with cost = 1
        return min(oneCnt, zeroCnt);

    }
};