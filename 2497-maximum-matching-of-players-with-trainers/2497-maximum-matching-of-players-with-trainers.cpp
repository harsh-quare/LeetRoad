class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // assign the player with minimum ability to the trainer with just enough capacity
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int minTrainerId = 0;
        int cnt = 0;
        for(int i = 0; i < players.size(); i++){
            int ab = players[i];
            int id = lower_bound(trainers.begin() + minTrainerId, trainers.end(), ab) - trainers.begin();

            if(id < trainers.size()) cnt++;
            minTrainerId = id + 1;  // so that previously assigned trainer isn't repeated again
        }

        return cnt;
    }
};