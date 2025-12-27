class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> active;
        for(int i = 0; i < n; i++) active.push(i);

        vector<int> meetingCnt(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        sort(meetings.begin(), meetings.end());

        for(auto& meeting: meetings){
            int start = meeting[0];
            int end = meeting[1]-1;

            // release all the booked rooms if they are done
            while(!pq.empty() && pq.top().first < start){
                active.push(pq.top().second);  // make the room active again
                pq.pop();  // pop this room 
            }

            if(!active.empty()){
                int room = active.top();
                active.pop();  // mark not active

                meetingCnt[room]++;
                pq.push({end, room});
            }
            else{
                int latestRoom = pq.top().second;
                long long roomMeetingEndTime = pq.top().first;
                pq.pop();

                long long waitTime = (roomMeetingEndTime + 1) - start;

                meetingCnt[latestRoom]++;
                pq.push({(long long)end + waitTime, latestRoom});
            }
        }

        int mostMeetings = 0;
        int ansIdx = -1;
        for(int i = 0; i < n; i++){
            if(meetingCnt[i] > mostMeetings){
                mostMeetings = meetingCnt[i];
                ansIdx = i;
            }
        }

        return ansIdx;
    }
};

// find lowest numbered available room
// the ans => I need the number of the room which had most meetings.  => keep track of number of meetings in each room
// to keep track of all the meetings and room getting finished => need a minHeap