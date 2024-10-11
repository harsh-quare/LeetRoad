class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<int, vector<int>, greater<int>> minSeatAvailable;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> departChair;
        vector<pair<int, int>> arrivalTimes;

        for(int i = 0; i < n; i++){
            minSeatAvailable.push(i);  //all chairs are available initially
            arrivalTimes.push_back({times[i][0], i});
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());

        for(int i = 0; i < n; i++){
            int arrTime = arrivalTimes[i].first;
            int frnd = arrivalTimes[i].second;

            while(!departChair.empty() && departChair.top().first <= arrTime){
                int chairToFree = departChair.top().second;  //free the seat from the friend leaving
                departChair.pop();
                minSeatAvailable.push(chairToFree);  //put it into available seats
            }

            //assign seat to current friend
            int assignedChair = minSeatAvailable.top();
            minSeatAvailable.pop();

            if(frnd == targetFriend){
                return assignedChair;
            }

            //add this friend's departure time and their assigned chair to the depart heap
            departChair.push({times[frnd][1], assignedChair});
        }

        return -1;
    }
};