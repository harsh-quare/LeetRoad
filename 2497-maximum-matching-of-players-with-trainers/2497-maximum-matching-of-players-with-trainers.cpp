class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // assign the player with minimum ability to the trainer with just enough capacity
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int cnt = 0;
        int i = 0, j = 0;
        while(i < players.size() && j < trainers.size()){
            if(players[i] <= trainers[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }

        return cnt;
    }
};