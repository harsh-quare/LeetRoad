class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int, int>> arrTime;
        priority_queue<int, vector<int>, greater<int>> availableChair;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> departChair;  //{depart Time, asssignedChair}

        for(int i = 0; i < n; i++){
            availableChair.push(i);
            arrTime.push_back({times[i][0], i});  //arrival time and friend number
        }

        sort(arrTime.begin(), arrTime.end());

        // start processing and assign chairs in order of their arrival time
        for(int i = 0; i < n; i++){
            int arTm = arrTime[i].first;
            int frndNumber = arrTime[i].second;

            while(!departChair.empty() && departChair.top().first <= arTm){
                //make this chair available, bcz the departure time is before or equal to cur arrival time
                availableChair.push(departChair.top().second);
                departChair.pop();
            }

            int assigned = availableChair.top();
            availableChair.pop();

            if(frndNumber == targetFriend) return assigned;

            departChair.push({times[frndNumber][1], frndNumber});
        }

        return -1;
    }
};